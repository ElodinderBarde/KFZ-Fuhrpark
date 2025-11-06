#pragma once

namespace Messerli::UI {
struct Draw {
    static void ClearScreen();

    static void GoTo(int x, int y);

    static void DrawBox(int x, int y, int width, int height);
};
}