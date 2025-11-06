#pragma once

#include "Data/DataConfig.h"

#include <string>

namespace Messerli::UI {
class ContentArea {
    int x_, y_, width_, height_;

public:
    ContentArea(int x, int y, int width, int height);

    void Clear() const;

    void PrintLine(int offsetY, const std::string& text) const;

    void PrintCentered(int offsetY, const std::string& text) const;

    static std::string DrawInputBox(const std::string& label);

    static void ArrayPrintPaged(Data::Fuhrpark::Enum::KfzType type, int startX, int startY, int maxRows, int Page);

    static void ShowPagedList(Data::Fuhrpark::Enum::KfzType type);
};
}