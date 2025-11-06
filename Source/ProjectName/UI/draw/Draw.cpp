#include "../UI/draw/Draw.h"
#include <iostream>
#include <windows.h>
#include "Data/Strings.h"

namespace Messerli::UI {
void Draw::ClearScreen()
{
    #ifdef _Win32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); COORD topLeft = {0, 0}; CONSOLE_SCREEN_BUFFER_INFO screen; DWORD written; GetConsoleScreenBufferInfo(hConsole, &screen); FillConsoleOutputCharacterA(hConsole, ' ', screen . dwSize . X * screen . dwSize . Y, topLeft, &written); FillConsoleOutputAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen . dwSize . X * screen . dwSize . Y, topLeft, &written); SetConsoleCursorPosition(hConsole, topLeft);
    #else
    std::cout << "\033[2J\033[1;1H"; // ANSI escape codes for clearing screen and moving cursor to top-left
    #endif
}

void Draw::GoTo(int x, int y)
{
    COORD pos{static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Draw::DrawBox(int x, int y, int width, int height)
{
    // Top edge
    GoTo(x, y);
    std::cout << Data::UI::edgeLeft;
    for (auto i = 0; i < width - 2; ++i) {
        std::cout << Data::UI::edgeTop;
    }
    std::cout << Data::UI::edgeRight;
    // Side edges
    for (auto i = 1; i < height - 1; ++i) {
        GoTo(x, y + i);
        std::cout << Data::UI::edgeSeparator;
        GoTo(x + width - 1, y + i);
        std::cout << Data::UI::edgeSeparator;
    }
    // Bottom edge
    GoTo(x, y + height - 1);
    std::cout << Data::UI::edgeLeft;
    for (auto i = 0; i < width - 2; ++i) {
        std::cout << Data::UI::edgeBottom;
    }
    std::cout << Data::UI::edgeRight;
}
}