#include "Types/StadtAuto.h"

#include "Data/DataConfig.h"
#include "Tools/ArrayManager.h"

namespace Messerli::Types {
StadtAuto::StadtAuto() :
    m_size(0)
{
    for (auto& i : m_vec) {
        i = nullptr;
    }
}

StadtAuto::~StadtAuto()
{
    for (auto i = 0; i < m_size; ++i) {
        delete m_vec[i];
    }
    m_size = 0;
}

bool StadtAuto::Insert(const std::string& typ, const bool sd, const long nr, const std::string& h)
{
    if (IsFull()) {
        return false;
    }
    m_vec[m_size++] = new Pkw(typ, sd, nr, h);
    return true;
}

bool StadtAuto::Insert(int axles, double capacity, long nr, const std::string& h, const std::string& model)
{
    if (IsFull())
        return false;
    m_vec[m_size++] = new Lkw(axles, capacity, nr, h, model);
    return true;
}

void StadtAuto::Display() const
{
    for (auto i = 0; i < m_size; ++i) {
        if (m_vec[i]) {
            m_vec[i] -> Display(); // ruft die bereits existierenden Display()-Implementierungen auf
        }
    }
}

bool StadtAuto::IsFull() const
{
    return m_size >= Max;
}

int StadtAuto::Size() const
{
    return m_size;
}
}