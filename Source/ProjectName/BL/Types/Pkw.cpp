#include "Types/Pkw.h"

#include "../UI/draw/Draw.h"
#include "Data/DataConfig.h"
#include "Data/Strings.h"
#include "Tools/ArrayManager.h"
#include "Tools/Function.h"

#include <iostream>

namespace Messerli::Types {
Pkw::Pkw(std::string typ, bool sd, long nr, const std::string& h) :
    Kfz(nr, h),
    m_PkwTyp(std::move(typ)),
    m_roofWindow(sd)
{
    Tools::ArrayManager::CreateDynamicArrayPkw();
    Data::Fuhrpark::Fuhrpark::arrayPkw[Data::Fuhrpark::Fuhrpark::PkwCounter++] = this;

    // std::cout << "Ein Objekt vom Typ Pkw wurde erstellt. \n";
}

Pkw::~Pkw()
{
    std::cout << "Ein Objekt vom Typ Pkw wurde zerstört. \n";
}

Pkw::Pkw(long nr, const std::string& hersteller) :
    Kfz(nr, hersteller)
{
}

Pkw::Pkw(const Kfz& other) :
    Kfz(other)
{
}

Pkw::Pkw(Kfz&& other) :
    Kfz(other)
{
}

Pkw::Pkw(const Pkw& other) :
    Kfz(other),
    m_PkwTyp(other . m_PkwTyp),
    m_roofWindow(other . m_roofWindow)
{
}

Pkw::Pkw(Pkw&& other) noexcept :
    Kfz(std::move(other)),
    m_PkwTyp(std::move(other . m_PkwTyp)),
    m_roofWindow(other . m_roofWindow)
{
}

Pkw& Pkw::operator=(const Pkw& other)

{
    if (this == &other)
        return *this;
    Kfz::operator=(other);
    m_PkwTyp = other . m_PkwTyp;
    m_roofWindow = other . m_roofWindow;
    return *this;
}

Pkw& Pkw::operator=(Pkw&& other) noexcept
{
    if (this == &other)
        return *this;
    Kfz::operator=(std::move(other));
    m_PkwTyp = std::move(other . m_PkwTyp);
    m_roofWindow = other . m_roofWindow;
    return *this;
}

std::string Pkw::GetTyp() const
{
    return m_PkwTyp;
}

void Pkw::SetTyp(const std::string& typ)
{
    m_PkwTyp = typ;
}

bool Pkw::HasRoofWindow() const
{
    return m_roofWindow;
}

void Pkw::SetRoofWindow(bool b)
{
    m_roofWindow = b;
}

void Pkw::Display() const
{
    Kfz::Display();

    std::string m_roofWindowStr = HasRoofWindow() ? "Ja" : "Nein";

    std::cout << Data::printOutput::modelName << m_PkwTyp << "\n";
    std::cout << Data::printOutput::roofWindow << m_roofWindowStr << " \n";
    std::cout << Data::Strings::line << "\n";
}

void Pkw::DisplayAt(int x, int y) const
{
    Kfz::DisplayAt(x, y);
    UI::Draw::GoTo(x, y + 3);
    std::cout << "Modell:         " << m_PkwTyp;
    UI::Draw::GoTo(x, y + 4);
    std::cout << "Schiebedach:    " << (m_roofWindow ? "Ja" : "Nein");
    UI::Draw::GoTo(x, y + 5);
    std::cout << "----------------------------------------";
}
}