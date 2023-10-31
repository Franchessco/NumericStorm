#pragma once
#include <array>

#include "../Fitting/Parameters.hpp"

namespace NumericStorm 
{
namespace Fitting 
{

template <typename T, size_t s>

class Bounds :public Parameters
{

public:
	template <typename ... Args>
	Bounds(Args... args)
		:Parameters(args...) {};


	Bounds<T,s> operator - (const Bounds<T,s>& other);
	Bounds<T,s> operator / (float denominator);

};

}
}





