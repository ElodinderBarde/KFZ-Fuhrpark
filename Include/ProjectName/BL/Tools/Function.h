#pragma once
#include "Data/DataConfig.h"
#include "Data/Strings.h"
#include "Types/Kfz.h"
#include "Types/Lkw.h"
#include "Types/Pkw.h"

namespace Messerli::Tools
{

struct Function
{
    static void InitializeApp();

    static void StringOutput(const std::string& str);

    static void SkipALine();

    static void PrintStatistics();

    static void SkipMultipleLines(int amount);

    static int GenerateInventoryNumber(Messerli::Data::Fuhrpark::Enum::KfzType kfz);

    static int ToIntSafe(const std::string& s);

    static double ToDoubleSafe(const std::string& s);
};
}
