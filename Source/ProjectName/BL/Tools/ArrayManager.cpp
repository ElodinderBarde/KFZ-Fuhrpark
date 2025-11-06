#include "Tools/ArrayManager.h"

#include "../UI/draw/Draw.h"
#include "Data/DataConfig.h"
#include "Data/Strings.h"
#include "Tools/Function.h"

#include <iostream>

namespace Messerli::Tools {
Types::Kfz** ArrayManager::CreateDynamicArray()
{
    if (Data::Fuhrpark::Fuhrpark::array != nullptr)
        return Data::Fuhrpark::Fuhrpark::array;

    Data::Fuhrpark::Fuhrpark::array = new Types::Kfz*[Data::Fuhrpark::FuhrparkMaxSize];
    for (auto i = 0; i < Data::Fuhrpark::FuhrparkMaxSize; ++i) {
        Data::Fuhrpark::Fuhrpark::array[i] = nullptr;
    }

    return Data::Fuhrpark::Fuhrpark::array;
}

Types::Pkw** ArrayManager::CreateDynamicArrayPkw()
{
    if (Data::Fuhrpark::Fuhrpark::arrayPkw != nullptr)
        return Data::Fuhrpark::Fuhrpark::arrayPkw;

    Data::Fuhrpark::Fuhrpark::arrayPkw = new Types::Pkw*[Data::Fuhrpark::FuhrparkMaxSize];
    for (auto i = 0; i < Data::Fuhrpark::FuhrparkMaxSize; ++i) {
        Data::Fuhrpark::Fuhrpark::arrayPkw[i] = nullptr;
    }

    return Data::Fuhrpark::Fuhrpark::arrayPkw;
}

Types::Lkw** ArrayManager::CreateDynamicArrayLkw()
{
    if (Data::Fuhrpark::Fuhrpark::arrayLkw != nullptr)
        return Data::Fuhrpark::Fuhrpark::arrayLkw;

    Data::Fuhrpark::Fuhrpark::arrayLkw = new Types::Lkw*[Data::Fuhrpark::FuhrparkMaxSize];
    for (auto i = 0; i < Data::Fuhrpark::FuhrparkMaxSize; ++i) {
        Data::Fuhrpark::Fuhrpark::arrayLkw[i] = nullptr;
    }

    return Data::Fuhrpark::Fuhrpark::arrayLkw;
}

bool ArrayManager::CheckArrayIfFull(Types::Kfz* const* array)
{
    for (auto i = 0; i < Data::Fuhrpark::FuhrparkMaxSize; ++i) {
        if (array[i] == nullptr) {
            return false; // mindestens ein slot ist frei
        }
    }
    return true;
}

bool ArrayManager::InsertVehicle(Types::Kfz* fahrzeug, int position, Types::Kfz** array)
{
    if (position < 0 || position >= Data::Fuhrpark::FuhrparkMaxSize) {
        return false;
    }
    if (array[position] != nullptr)

        return false;

    array[position] = fahrzeug;
    return true;
}

void ArrayManager::DeleteArray(Types::Kfz** array)
{
    if (!array) {
        return;
    }
    for (auto i = 0; i < Data::Fuhrpark::FuhrparkMaxSize; ++i) {
        delete array[i];
    }
    delete[] array;
    Data::Fuhrpark::Fuhrpark::array = nullptr;
    Data::Fuhrpark::Fuhrpark::FahrzeugCounter = 0;
    Data::Fuhrpark::Fuhrpark::PkwCounter = 0;
    Data::Fuhrpark::Fuhrpark::LkwCounter = 0;
}

void ArrayManager::ArrayPrint(Types::Kfz** fuhrpark, int startX, int startY, int maxRows)
{
    Function::StringOutput(Data::printOutput::CarParkPrintHeader);

    Function::PrintStatistics();

    auto currentRow = 0;
    for (auto i = 0; i < Data::Fuhrpark::FuhrparkMaxSize; ++i) {
        if (fuhrpark[i] != nullptr) {
            // Stoppe, wenn wir die maximalen Zeilen erreicht haben
            if (currentRow >= maxRows)
                break;

            // Gehe zur gewünschten Position
            UI::Draw::GoTo(startX, startY + currentRow);
            std::cout << "[ Pos: " << i + 1 << "] ";
            fuhrpark[i] -> Display();

            currentRow++;
        } else {
            // Optional: leere Position anzeigen oder überspringen
            // Draw::GoTo(startX, startY + currentRow);
            // std::cout << "[" << i + 1 << "] leer\n";
        }
    }
}

void ArrayManager::ArrayPrint(Types::Pkw** fuhrpark, int startX, int startY, int maxRows)
{
    Function::StringOutput(Data::printOutput::CarParkPrintHeaderPkw);
    Function::PrintStatistics();

    auto currentRow = 0;
    for (auto i = 0; i < Data::Fuhrpark::FuhrparkMaxSize; ++i) {
        if (fuhrpark[i] != nullptr) {
            // Stoppe, wenn wir die maximalen Zeilen erreicht haben
            if (currentRow >= maxRows)
                break;

            // Gehe zur gewünschten Position
            UI::Draw::GoTo(startX, startY + currentRow);
            std::cout << "[ Pos: " << i + 1 << "] ";
            fuhrpark[i] -> Display();

            currentRow++;
        } else {
            // Optional: leere Position anzeigen oder überspringen
            // Draw::GoTo(startX, startY + currentRow);
            // std::cout << "[" << i + 1 << "] leer\n";
        }
    }
}

void ArrayManager::ArrayPrint(Types::Lkw** fuhrpark, int startX, int startY, int maxRows)
{
    Function::StringOutput(Data::printOutput::CarParkPrintHeaderLkw);
    Function::PrintStatistics();

    auto currentRow = 0;
    for (auto i = 0; i < Data::Fuhrpark::FuhrparkMaxSize; ++i) {
        if (fuhrpark[i] != nullptr) {
            // Stoppe, wenn wir die maximalen Zeilen erreicht haben
            if (currentRow >= maxRows)
                break;

            // Gehe zur gewünschten Position
            UI::Draw::GoTo(startX, startY + currentRow);
            std::cout << "[ Pos: " << i + 1 << "] ";
            fuhrpark[i] -> Display();

            currentRow++;
        } else {
            // Optional: leere Position anzeigen oder überspringen
            // Draw::GoTo(startX, startY + currentRow);
            // std::cout << "[" << i + 1 << "] leer\n";
        }
    }
}

void ArrayManager::ArrayPrintAll()
{
    std::cout << "\033[36m";                                    // cyan
    ArrayPrint(Data::Fuhrpark::Fuhrpark::array, 10, 5, 10);     // Allgemein
    std::cout << "\033[91m";                                    // rot
    ArrayPrint(Data::Fuhrpark::Fuhrpark::arrayPkw, 10, 17, 10); // PKW-Bereich
    std::cout << "\033[92m";                                    // grün
    ArrayPrint(Data::Fuhrpark::Fuhrpark::arrayLkw, 10, 29, 10); // LKW-Bereich
    std::cout << "\033[0m";                                     // Reset Farbe
}
} // namespace Messerli::Tools