#pragma once
#include <array>

#include "Parameters.hpp"

namespace NumericStorm {
namespace Fitting {

template <typename T, size_t s>
class Bounds : public Parameters<T, s> {

public:
    
    template <typename... Args>
    Bounds(Args... args) : Parameters<T, s>(args...) {}
    


// Copy assignment operator
Bounds<T, s>& operator=(const Bounds<T, s>& other) 
{
    if (this == &other) 
        {return *this;}
    m_parameters = other.getParamters();
    return *this;
}

// Arithmetic operations
Bounds<T, s> operator+(const Bounds<T, s>& other) const {
    Bounds<T, s> result = *this;
    for (int i = 0; i < s; i++) 
        {result[i] = (*this)[i] + other[i];}
    
    return result;
}
Bounds<T, s> operator-(const Bounds<T, s>& other) const {
    Bounds<T, s> result = *this;
    for (int i = 0; i < s; i++) 
        {result[i] = (*this)[i] - other[i];}
    
    return result;
}
Bounds<T, s> operator*(const float& mult) const {
    Bounds<T, s> result = *this;
    for (int i = 0; i < s; i++) 
        {result[i] = (*this)[i] * mult;}
    
    return result;
}
Bounds<T, s> operator/(const float& denominator) const {
    Bounds<T, s> result = *this;
    for (int i = 0; i < s; i++) 
        {result[i] = (*this)[i] / denominator;}

    return result;
}

// Compound assignment operators
Bounds<T, s>& operator+=(const Bounds<T, s>& other) {
    for (int i = 0; i < s; i++) 
        {(*this)[i] += other[i];}

    return *this;
}
Bounds<T, s>& operator-=(const Bounds<T, s>& other) {
    for (int i = 0; i < s; i++) 
        {(*this)[i] -= other[i];}

    return *this;
}
Bounds<T, s>& operator*=(const float& mult) {
    for (int i = 0; i < s; i++) 
    {(*this)[i] *= mult;}

    return *this;
}
Bounds<T, s>& operator/=(const float& denominator) {
    for (int i = 0; i < s; i++) 
        {(*this)[i] /= denominator;}

    return *this;
}

};
  
}
}
