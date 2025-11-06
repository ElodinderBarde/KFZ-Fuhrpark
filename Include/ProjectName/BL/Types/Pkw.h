#pragma once
#include "Kfz.h"

namespace Messerli::Types {
class Pkw : public Kfz {
    std::string m_PkwTyp;
    bool m_roofWindow;

public:
    Pkw();

    Pkw(std::string typ, bool sd, long nr, const std::string& h);

    ~Pkw() override;

    Pkw(long nr, const std::string& hersteller);

    Pkw(const Kfz& other);

    Pkw(Kfz&& other);

    Pkw(const Pkw& other);

    Pkw(Pkw&& other) noexcept;

    Pkw& operator=(const Pkw& other);

    Pkw& operator=(Pkw&& other) noexcept;

    std::string GetTyp() const;

    void SetTyp(const std::string& typ);

    bool HasRoofWindow() const;

    void SetRoofWindow(bool sd);

    void Display() const override;

    void DisplayAt(int x, int y) const override;
};
}