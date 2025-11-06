#pragma once
#include "Types/Kfz.h"

namespace Messerli::Types {
class Lkw : public Kfz {
    int m_Axles;
    double m_LoadCapacity;
    std::string m_model;

public:
    Lkw();

    Lkw(int axles, double capacity, long nr, const std::string& h, const std::string& model);

    Lkw(long nr, const std::string& hersteller);

    ~Lkw() override;

    Lkw(const Kfz& other);

    Lkw(Lkw&& other) noexcept;

    Lkw(const Lkw& other);

    Lkw& operator=(const Lkw& other);

    Lkw& operator=(Lkw&& other) noexcept;

    int GetAxles() const;

    void SetAxles(int a);

    double GetLoadCapacity() const;

    void SetLoadCapacity(double capacity);

    void Display() const override;

    void DisplayAt(int x, int y) const override;
};
}