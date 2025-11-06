#include "Types/Lkw.h"

#include "../UI/draw/Draw.h"
#include "Data/DataConfig.h"
#include "Data/Strings.h"
#include "Tools/ArrayManager.h"
#include "Tools/Function.h"

#include <iostream>

namespace Messerli::Types {
Lkw::Lkw(const int axles, double capacity, long nr, const std::string& h, const std::string& model) :
    Kfz(nr, h),
    m_Axles(axles),
    m_LoadCapacity(capacity),
    m_model(model)
{
    Tools::ArrayManager::CreateDynamicArrayLkw();
    Data::Fuhrpark::Fuhrpark::arrayLkw[Data::Fuhrpark::Fuhrpark::LkwCounter++] = this;

    // std::cout << "Ein Objekt vom Typ Lkw wurde erstellt. \n";
}

Lkw::Lkw(long nr, const std::string& hersteller) :
    Kfz(nr, hersteller),
    m_Axles(0),
    m_LoadCapacity(0)
{
}

Lkw::~Lkw()
{
    std::cout << "Ein Objekt vom Typ Lkw wurde zerstört.\n";
}

Lkw::Lkw(const Kfz& other) :
    Kfz(other),
    m_Axles(0),
    m_LoadCapacity(0)
{
}

Lkw::Lkw(Lkw&& other) noexcept :
    Kfz(std::move(other)),
    m_Axles(other . m_Axles),
    m_LoadCapacity(other . m_LoadCapacity)
{
}

Lkw::Lkw(const Lkw& other) :
    Kfz(other),
    m_Axles(other . m_Axles),
    m_LoadCapacity(other . m_LoadCapacity)
{
}

Lkw& Lkw::operator=(const Lkw& other)
{
    if (this == &other)
        return *this;

    Kfz::operator=(other);
    m_Axles = other . m_Axles;
    m_LoadCapacity = other . m_LoadCapacity;
    return *this;
}

Lkw& Lkw::operator=(Lkw&& other) noexcept
{
    if (this == &other)
        return *this;

    Kfz::operator=(std::move(other));
    m_Axles = other . m_Axles;
    m_LoadCapacity = other . m_LoadCapacity;

    other . m_Axles = 0;
    other . m_LoadCapacity = 0.0;
    return *this;
}

int Lkw::GetAxles() const
{
    return m_Axles;
}

void Lkw::SetAxles(int a)
{
    m_Axles = a;
}

double Lkw::GetLoadCapacity() const
{
    return m_LoadCapacity;
}

void Lkw::SetLoadCapacity(const double capacity)
{
    m_LoadCapacity = capacity;
}

void Lkw::Display() const
{
    Kfz::Display();

    std::cout << Data::printOutput::amountAxels << GetAxles() << "\n";
    std::cout << Data::printOutput::loadCapacity << GetLoadCapacity() << " \n";
    std::cout << Data::Strings::line << "\n";
}

void Lkw::DisplayAt(int x, int y) const
{
    Kfz::DisplayAt(x, y);
    UI::Draw::GoTo(x, y + 3);
    Tools::Function::StringOutput(Data::printOutput::modelName + m_model);
    UI::Draw::GoTo(x, y + 4);
    Tools::Function::StringOutput(Data::printOutput::amountAxels + std::to_string(m_Axles));
    UI::Draw::GoTo(x, y + 5);
    Tools::Function::StringOutput(Data::Strings::line);
    Tools::Function::SkipALine();
}
} // namespace Messerli::Types