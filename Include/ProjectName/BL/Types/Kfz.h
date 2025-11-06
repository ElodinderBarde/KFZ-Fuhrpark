#pragma once
#include <string>

namespace Messerli::Types {
class Kfz {
    long m_Nr;
    std::string m_Hersteller;

public:
    Kfz();

    Kfz(long nr, std::string hersteller);

    virtual ~Kfz();

    Kfz(const Kfz& other);

    Kfz(Kfz&& other) noexcept;

    Kfz& operator=(const Kfz& other);

    Kfz& operator=(Kfz&& other) noexcept;

    long GetM_Nr() const;

    void SetM_Nr(long nr);

    std::string GetM_Hersteller() const;

    void SetM_Hersteller(const std::string& hersteller);

    virtual void Display() const;

    virtual void DisplayAt(int x, int y) const;
};
}