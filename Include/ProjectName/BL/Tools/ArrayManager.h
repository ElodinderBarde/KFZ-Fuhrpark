#pragma once
#include "Types/Kfz.h"
#include "Types/Lkw.h"
#include "Types/Pkw.h"

namespace Messerli::Tools {
struct ArrayManager {
    static Types::Kfz** CreateDynamicArray();

    static Types::Pkw** CreateDynamicArrayPkw();

    static Types::Lkw** CreateDynamicArrayLkw();

    static bool CheckArrayIfFull(Types::Kfz* const* array);

    static bool InsertVehicle(Types::Kfz* fahrzeug, int position, Types::Kfz** array);

    static void DeleteArray(Types::Kfz** array);

    static void ArrayPrint(Types::Kfz** fuhrpark, int startX, int startY, int maxRows);

    static void ArrayPrint(Types::Pkw** fuhrpark, int startX, int startY, int maxRows);

    static void ArrayPrint(Types::Lkw** fuhrpark, int startX, int startY, int maxRows);

    static void ArrayPrintAll();
};
}