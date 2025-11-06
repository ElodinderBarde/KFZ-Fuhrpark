#pragma once
#include <string>

namespace Messerli::UI {
struct DrawManager {
    static void DrawMenu();

    static void ClearArea(int x, int y, int width, int height);
};
}