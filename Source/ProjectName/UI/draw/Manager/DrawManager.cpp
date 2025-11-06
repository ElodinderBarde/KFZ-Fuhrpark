#include "../UI/draw/Manager/DrawManager.h"

#include <conio.h>
#include <string_view>
#include "../UI/draw/Draw.h"
#include "../UI/draw/tools/MenuActions.h"
#include "Data/Strings.h"
#include "Tools/Function.h"

namespace Messerli::UI {namespace Tools::Menu {
    class MenuActions;
    }

    constexpr std::string_view mainMenuItems[] = {Data::Menu::mainMenuNewPkw, Data::Menu::mainMenuNewLkw, Data::Menu::mainMenuPrintAll, Data::Menu::mainMenuPrintPkw, Data::Menu::mainMenuPrintLkw, Data::Menu::mainMenuExit};
    constexpr int mainMenuItemCount = sizeof(mainMenuItems) / sizeof(mainMenuItems[0]);

    namespace MenuActions {
    }

    void DrawManager::DrawMenu()
    {
        auto currentSelection = 0;
        auto running = true;

        while (running) {
            Draw::ClearScreen();

            Draw::DrawBox(2, 0, 92, 5);
            Draw::GoTo(25, 1);
            Messerli::Tools::Function::StringOutput(Data::Menu::mainMenuTitle);
            Draw::GoTo(4, 1);

            Draw::DrawBox(2, 4, 33, 30);
            auto x = 4, y = 6;

            // --- Menü ausgeben ---
            for (auto i = 0; i < mainMenuItemCount; ++i) {
                Draw::GoTo(x, y + i);

                if (i == currentSelection) {
                    std::cout << "\033[7m" << mainMenuItems[i] << "\033[0m\n"; // Invertierte Farbe
                } else {
                    std::cout << mainMenuItems[i] << '\n';
                }
            }

            Draw::DrawBox(34, 4, 60, 30);
            Draw::DrawBox(2, 33, 92, 4);

            // Steuerungshilfe ausgeben
            Draw::GoTo(4, 34);
            Messerli::Tools::Function::StringOutput(Data::Menu::navigationHelperEnter);
            Draw::GoTo(4, 35);
            Messerli::Tools::Function::StringOutput(Data::Menu::navigationHelperUpDown);
            Draw::GoTo(30, 34);
            Messerli::Tools::Function::StringOutput(Data::Menu::navigationHelperBack);
            Draw::GoTo(30, 35);
            Messerli::Tools::Function::StringOutput(Data::Menu::navigationHelperEsc);

            // Taseneingabe verarbeiten

            int key = _getch();

            if (key == 224) {
                key = _getch(); // Pfeiltaste erkannt, nächsten Wert lesen

                switch (key) {
                    case 72: // Pfeil nach oben
                    {
                        currentSelection = (currentSelection - 1 + mainMenuItemCount) % mainMenuItemCount;
                        break;
                    }
                    case 80: // Pfeil nach unten
                    {
                        currentSelection = (currentSelection + 1) % mainMenuItemCount;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            } else if (key == 13) // Enter-Taste
            {
                ClearArea(35, 5, 58, 28);

                using Tools::Menu::MenuActions;

                running = MenuActions::MenuSwitch(currentSelection, running);

                Draw::GoTo(40, 20); // Positioniere den Cursor für die Ausgabe

                std::cout << "Auswahl bestätigt: " << mainMenuItems[currentSelection] << std::endl;
            } else if (key == 'q' || key == 'Q') // Q-Taste zum Beenden
            {
                running = false;
            } else if (key == 27) // ESC-Taste zum Beenden
            {
                running = false;
            }
        }
    }

    void DrawManager::ClearArea(int x, int y, int width, int height)
    {
        for (auto i = 0; i < height; ++i) {
            Draw::GoTo(x, y + i);
            std::cout << std::string(width, ' ');
        }
    }
}