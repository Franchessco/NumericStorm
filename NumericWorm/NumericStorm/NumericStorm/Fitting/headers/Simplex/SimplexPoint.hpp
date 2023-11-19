#pragma once
#include "../Parameters.hpp"
#include "../Bounds.hpp"

namespace NumericStorm 
{
namespace Fitting {
template <typename T_p, size_t s_p>
class SimplexPoint :public Parameters<T_p,s_p>
{
public:
    template<class ... Args>
    SimplexPoint(Args ...args)
        :Parameters<T_p, s_p>(args...) {};
    SimplexPoint(std::array<T_p, s_p> parameters)
        :Parameters<T_p, s_p>(parameters) {};
    void setToBounds(const Bounds<T_p,s_p> minBounds, const Bounds<T_p,s_p> maxBounds) 
    {
        setToMinBounds(minBounds);
        setToMaxBounds(maxBounds);
    }

private:
    void setToMinBounds(const Bounds<T_p,s_p> minBounds) 
    {
    for (int i = 0; i < s_p; i++)
        if (this->m_parameters[i] < minBounds[i])
            this->m_parameters[i] = minBounds[i];
    }
    void setToMaxBounds(const Bounds<T_p,s_p> maxBounds) 
    {
    for (int i = 0; i < s_p; i++)
        if (this->m_parameters[i] > maxBounds[i])
            this->m_parameters[i] = maxBounds[i];
    }
};
    }
}

