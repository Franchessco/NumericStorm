#pragma once
#include <array>

#include "../Parameters.hpp"
namespace NumericStorm 
{

template <typename T, size_t s>

class Bounds :public Parameters
{

public:
	template <typename ... Args>
	Bounds(Args... args)
		:Parameters(args...) {};
	
	//TODO ovrride method for comparacent by value instead by chi2
};

}





