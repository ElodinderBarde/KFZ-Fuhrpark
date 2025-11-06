#include "Tools/Function.h"

#include "../UI/draw/Manager/DrawManager.h"
#include "Data/DataConfig.h"
#include "Tools/ArrayManager.h"
#include "Types/Kfz.h"
#include <charconv>
#include <iostream>
#include <windows.h>

namespace Messerli::Tools
{

void Function::InitializeApp()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ArrayManager::CreateDynamicArray();
    ArrayManager::CreateDynamicArrayPkw();
    ArrayManager::CreateDynamicArrayLkw();
    // Data::Fuhrpark::Objects::CreateCarpark();

    UI::DrawManager::DrawMenu();
}

void Function::StringOutput(const std::string& str)
{
    std::cout << str;
}

void Function::SkipALine()
{
    std::cout << std::endl;
}

void Function::PrintStatistics()
{
    SkipALine();

    StringOutput(Data::Strings::wiggLine);
    SkipALine();

    StringOutput(Data::printOutput::TypesInLot + ": ");
    StringOutput(std::to_string(Data::Fuhrpark::Fuhrpark::FahrzeugCounter));
    SkipALine();
    StringOutput(Data::printOutput::of);
    SkipALine();
    StringOutput(std::to_string(Data::Fuhrpark::Fuhrpark::PkwCounter) + " ");
    StringOutput(Data::printOutput::Pkw);

    SkipALine();
    StringOutput(std::to_string(Data::Fuhrpark::Fuhrpark::LkwCounter) + " ");
    StringOutput(Data::printOutput::Lkw);
    SkipALine();

    StringOutput(Data::Strings::wiggLine);

    SkipALine();
}

void Function::SkipMultipleLines(int amount)
{
    for (auto i = 0; i < amount; i++)
    {
        SkipALine();
    }
}

int Function::GenerateInventoryNumber(Data::Fuhrpark::Enum::KfzType type)
{
    auto prefix = 0;
    switch (type)
    {
    case Data::Fuhrpark::Enum::KfzType::Pkw:
        prefix = 1;
        break;
    case Data::Fuhrpark::Enum::KfzType::Lkw:
        prefix = 2;
        break;
    }

    static auto counter = 0;
    return prefix * 10000 + ++counter;
}

int Function::ToIntSafe(const std::string& s)
{
    int value{};
    std::from_chars(s.data(), s.data() + s.size(), value);
    return value;
}

double Function::ToDoubleSafe(const std::string& s)
{
    double value{};
    std::from_chars(s.data(), s.data() + s.size(), value);
    return value;
}
}
