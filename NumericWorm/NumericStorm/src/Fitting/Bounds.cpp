#include "headers/Fitting/Bounds.hpp"

namespace NumericStorm 
{
namespace Fitting 
{
template<typename T, size_t s>
Bounds<T, s> Bounds<T, s>::operator-(const Bounds<T, s>& other)
{
	for (int i = 0; i < s; i++)
		*this[i] = *this[i] - other[i];
	return *this;
}

template<typename T, size_t s>
Bounds<T, s> Bounds<T, s>::operator / (float denominator)
{
	for (auto var : m_parameters)
		var / denominator;
	return *this;
}
//TODO ovrride method for comparacent by value instead by chi2

}
}