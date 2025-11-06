#include "../UI/draw/Manager/ContentArea.h"

#include <conio.h>
#include "../UI/draw/Draw.h"
#include "Tools/ArrayManager.h"
#include "Tools/Function.h"

#include <iostream>

namespace Messerli::UI {
ContentArea::ContentArea(int x, int y, int width, int height) :
    x_(x),
    y_(y),
    width_(width),
    height_(height)
{
}

void ContentArea::Clear() const
{
    for (auto i = 0; i < height_; ++i) {
        Draw::GoTo(x_, y_ + i);
        std::cout << std::string(width_, ' ');
    }
}

void ContentArea::PrintLine(int offsetY, const std::string& text) const
{
    Draw::GoTo(x_, y_ + offsetY);
    std::cout << text;
}

void ContentArea::PrintCentered(int offsetY, const std::string& text) const
{
    int centerX = x_ + (width_ - static_cast<int>(text . size())) / 2;
    Draw::GoTo(centerX, y_ + offsetY);
    std::cout << text;
}

std::string ContentArea::DrawInputBox(const std::string& label)
{
    constexpr auto boxX = 34;
    constexpr auto boxY = 29;
    constexpr auto boxWidth = 60;
    constexpr auto boxHeight = 5;

    Draw::DrawBox(boxX, boxY, boxWidth, boxHeight);

    Draw::GoTo(boxX + 1, boxY + 2);
    std::cout << "Tragen Sie ein -> " << label << ": ";

    std::string input;
    std::getline(std::cin >> std::ws, input);

    for (auto i = 0; i < boxHeight - 1; ++i) {
        Draw::GoTo(boxX + 1, boxY + i + 1);
        std::cout << std::string(boxWidth - 2, ' ');
    }

    return input;
}

void ContentArea::ArrayPrintPaged(Data::Fuhrpark::Enum::KfzType type, int startX, int startY, int maxRows, int page)
{
    using namespace Data::Fuhrpark;
    // Arrays sicherstellen
    if (!Fuhrpark::array)
        Tools::ArrayManager::CreateDynamicArray();
    if (!Fuhrpark::arrayPkw)
        Tools::ArrayManager::CreateDynamicArrayPkw();
    if (!Fuhrpark::arrayLkw)
        Tools::ArrayManager::CreateDynamicArrayLkw();

    // Feste Innenmaße der rechten Box (zu deinem Layout passend)
    constexpr auto contentWidth = 58;  // 60 - 2 Rahmen
    constexpr auto contentHeight = 28; // 30 - 2 Rahmen
    constexpr auto rowH = 7;           // Blockhöhe je Fahrzeug (zu DisplayAt passend)

    // maxRows an Content-Höhe kappen
    int effectiveMaxRows = maxRows;
    if (effectiveMaxRows * rowH > contentHeight)
        effectiveMaxRows = contentHeight / rowH; // -> 4

    const int cap = FuhrparkMaxSize;

    // Anzahl vorhandener Elemente (nur non-null)
    auto totalItems = 0;
    switch (type) {
        case Enum::KfzType::All: for (auto i = 0; i < cap; ++i) {
                if (Fuhrpark::array[i])
                    ++totalItems;
            }
            break;
        case Enum::KfzType::Pkw: for (auto i = 0; i < cap; ++i) {
                if (Fuhrpark::arrayPkw[i])
                    ++totalItems;
            }
            break;
        case Enum::KfzType::Lkw: for (auto i = 0; i < cap; ++i) {
                if (Fuhrpark::arrayLkw[i])
                    ++totalItems;
            }
            break;
        default: return;
    }

    // Contentbereich vollständig leeren (genau 28 Zeilen)
    for (auto y = 0; y < contentHeight; ++y) {
        Draw::GoTo(startX, startY + y);
        std::cout << std::string(contentWidth, ' ');
    }

    if (totalItems == 0) {
        Draw::GoTo(startX, startY);
        std::cout << "(keine Fahrzeuge vorhanden)";
        return;
    }

    // Seitenberechnung und Clamping
    const int totalPages = (totalItems + effectiveMaxRows - 1) / effectiveMaxRows;
    if (page < 0)
        page = 0;
    if (page >= totalPages)
        page = totalPages - 1;

    const int startOrdinal = page * effectiveMaxRows;
    const int endOrdinal = startOrdinal + effectiveMaxRows; // exklusiv

    // Rendern der n-ten non-null Einträge
    auto seen = 0;  // bisher gesehene non-null
    auto shown = 0; // auf dieser Seite gezeichnete Einträge
    switch (type) {
        case Enum::KfzType::All: for (auto i = 0; i < cap && shown < effectiveMaxRows; ++i) {
                if (!Fuhrpark::array[i])
                    continue;
                if (seen >= startOrdinal && seen < endOrdinal) {
                    Fuhrpark::array[i] -> DisplayAt(startX, startY + shown * rowH);
                    ++shown;
                }
                ++seen;
            }
            break;

        case Enum::KfzType::Pkw: for (auto i = 0; i < cap && shown < effectiveMaxRows; ++i) {
                if (!Fuhrpark::arrayPkw[i])
                    continue;
                if (seen >= startOrdinal && seen < endOrdinal) {
                    Types::Pkw* k = Fuhrpark::arrayPkw[i]; // Upcast
                    k -> DisplayAt(startX, startY + shown * rowH);
                    ++shown;
                }

                ++seen;
            }
            break;

        case Enum::KfzType::Lkw: for (auto i = 0; i < cap && shown < effectiveMaxRows; ++i) {
                if (!Fuhrpark::arrayLkw[i])
                    continue;
                if (seen >= startOrdinal && seen < endOrdinal) {
                    Types::Lkw* k = Fuhrpark::arrayLkw[i]; // Upcast
                    k -> DisplayAt(startX, startY + shown * rowH);
                    ++shown;
                }
                ++seen;
            }

            break;
    }

    const int footerY = startY + contentHeight - 1;
    Draw::GoTo(startX, footerY);
    std::cout << std::string(contentWidth, ' ');
    Draw::GoTo(startX, footerY);
    std::cout << "Seite " << (page + 1) << " / " << totalPages << "   (<-/-> fuer Seite, B = zurueck)";
}

void ContentArea::ShowPagedList(Data::Fuhrpark::Enum::KfzType type)
{
    auto page = 0;
    constexpr auto startX = 37;
    constexpr auto startY = 7;
    constexpr auto contentHeight = 28;
    constexpr auto rowH = 7;
    constexpr int maxRows = contentHeight / rowH;
    auto running = true;

    while (running) {
        // Nur Anzeige
        ArrayPrintPaged(type, startX, startY, maxRows, page);

        int ch = _getch();
        if (ch == 0 || ch == 224) {
            ch = _getch();
            switch (ch) {
                case 75: // ←
                    --page;
                    break;
                case 77: // →
                    ++page;
                    break;
            }
        } else {
            switch (ch) {
                case 'b':
                case 'B': running = false; // Schleife verlassen
                    break;
                case 'q':
                case 'Q': exit(0); // Programm beenden
            }
        }

        // Seitenbegrenzung
        if (page < 0)
            page = 0;
        if (page > 50) // temporäres Limit (z. B. 50 Seiten max.)
            page = 50;
    }
}
}