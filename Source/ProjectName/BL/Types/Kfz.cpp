#include "Types/Kfz.h"

#include "../UI/draw/Draw.h"
#include "Data/DataConfig.h"
#include "Data/Strings.h"
#include "Tools/ArrayManager.h"
#include "Tools/Function.h"

#include <iostream>
#include <string>

namespace Messerli::Types {
Kfz::Kfz(long nr, std::string hersteller) :
    m_Nr(nr),
    m_Hersteller(std::move(hersteller))
{
    Tools::Function::SkipMultipleLines(10);

    // Sicherstellen, dass das Hauptarray existiert
    auto fuhrpark = Tools::ArrayManager::CreateDynamicArray();
    if (fuhrpark == nullptr) {
        std::cerr << "[Error] Fuhrpark konnte nicht erstellt werden!\n";
        return;
    }

    // Prüfen, ob noch Platz im Fuhrpark ist
    if (Data::Fuhrpark::Fuhrpark::FahrzeugCounter >= Data::Fuhrpark::FuhrparkMaxSize) {
        Data::Fuhrpark::FuhrparkMaxSize += 100;
        std::cout << "\nDer Fuhrpark ist voll. Es können keine weiteren Fahrzeuge hinzugefügt werden.\n";
        std::cout << "\nZum Glück hast du unbegrenzt Geld und dein Nachbar hat sich für eine kleine menge Geld dafür bereit erklärt, dir etwas angrenzendes land zu verkaufen\n";
    }

    // Fahrzeug korrekt eintragen
    fuhrpark[Data::Fuhrpark::Fuhrpark::FahrzeugCounter] = this;

    // Jetzt erst den Zähler erhöhen
    Data::Fuhrpark::Fuhrpark::FahrzeugCounter++;

    // Debugausgabe (optional)
    // std::cout << "\nKfz erstellt und in Fuhrpark eingetragen. Index: "
    //           << Data::Fuhrpark::Fuhrpark::FahrzeugCounter - 1 << "\n";
}

Kfz::~Kfz()
{
    std::cout << "Das Objekt vom Typ Kfz wurde zerstört.\n";
}

Kfz::Kfz(const Kfz& other) :
    m_Nr(other . m_Nr),
    m_Hersteller(other . m_Hersteller)
{
    std::cout << "Copy-Konstruktor von Kfz aufgerufen.\n";
}

Kfz::Kfz(Kfz&& other) noexcept :
    m_Nr(other . m_Nr),
    m_Hersteller(std::move(other . m_Hersteller))
{
    std::cout << "Move-Konstruktor von Kfz aufgerufen.\n";
    other . m_Nr = 0;
    other . m_Hersteller . clear();
}

Kfz& Kfz::operator=(const Kfz& other)
{
    if (this == &other)
        return *this;

    m_Nr = other . m_Nr;
    m_Hersteller = other . m_Hersteller;

    std::cout << "Copy-Assignment von Kfz ausgeführt.\n";
    return *this;
}

Kfz& Kfz::operator=(Kfz&& other) noexcept
{
    if (this == &other)
        return *this;

    m_Nr = other . m_Nr;
    m_Hersteller = std::move(other . m_Hersteller);

    other . m_Nr = 0;
    other . m_Hersteller . clear();
    std::cout << "Move-Assignment von Kfz ausgeführt.\n";
    return *this;
}

long Kfz::GetM_Nr() const
{
    return m_Nr;
}

void Kfz::SetM_Nr(long nr)
{
    m_Nr = nr;
}

std::string Kfz::GetM_Hersteller() const
{
    return m_Hersteller;
}

void Kfz::SetM_Hersteller(const std::string& hersteller)
{
    m_Hersteller = hersteller;
}

void Kfz::Display() const
{
    Tools::Function::SkipALine();
    std::cout << Data::Strings::line << "\n";
    std::cout << "Kfz-Nummer:     " << m_Nr << "\n";
    std::cout << "Kfz-Hersteller: " << m_Hersteller << "\n";
}

void Kfz::DisplayAt(int x, int y) const
{
    UI::Draw::GoTo(x, y);
    Tools::Function::StringOutput(Data::Strings::line);
    UI::Draw::GoTo(x, y + 1);
    Tools::Function::StringOutput(Data::printOutput::inventoryNumber + std::to_string(m_Nr));
    UI::Draw::GoTo(x, y + 2);
    Tools::Function::StringOutput(Data::printOutput::brandName + m_Hersteller);
}
}