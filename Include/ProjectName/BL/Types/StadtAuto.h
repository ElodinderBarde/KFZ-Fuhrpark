#pragma once
#include "Pkw.h"

namespace Messerli::Types {
static constexpr auto Max = 100;

class StadtAuto {
    Kfz* m_vec[Max];
    int m_size;

public:
    StadtAuto();

    ~StadtAuto();

    StadtAuto(const StadtAuto&) = delete;

    StadtAuto& operator=(const StadtAuto&) = delete;

    StadtAuto(StadtAuto&&) = delete;

    StadtAuto& operator=(StadtAuto&&) = delete;

    bool Insert(const std::string& typ, bool sd, long nr, const std::string& h);

    bool Insert(int axles, double capacity, long nr, const std::string& h, const std::string& model);

    void Display() const;

    bool IsFull() const;

    int Size() const;
};
}