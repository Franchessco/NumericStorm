#include "Bounds.hpp"
#include "Bounds.hpp"
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

template<typename T, size_t s>
Bounds<T, s> Bounds<T, s>::operator+(const Bounds<T, s>& other)
{
	for(int i=0;i<size;i++)
		*(this[i]) = *this[i] + other[i]

	return *this;
}

template<typename T, size_t s>
Bounds<T, s> Bounds<T, s>::operator*(float mult)
{
	for (int i=0; i <s; i++)
		*(this[i]) = mult * (*(this[i]))
	return *this;
}

template<typename T, size_t s>
Bounds<T, s> Bounds<T, s>::operator-(const Bounds<T, s>& other)
{
	for (int i = 0; i < s; i++)
		*this[i] = *this[i] + other[i];
	return *this;
}

//TODO ovrride method for comparacent by value instead by chi2

}
}