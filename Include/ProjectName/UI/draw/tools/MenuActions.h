#pragma once

namespace Messerli::UI::Tools::Menu {
class MenuActions {
public:
    static bool MenuSwitch(int currentSelection, bool& running);

    static void AddPkw();

    static void AddLkw();

    static void ShowAll();

    static void ShowPkw();

    static void ShowLkw();
};
}