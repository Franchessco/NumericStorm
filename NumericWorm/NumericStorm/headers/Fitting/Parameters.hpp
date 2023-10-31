#pragma once
#include <array>
#include <string>

#include "Bounds.hpp"

namespace NumericStorm{
namespace Fitting{

template <typename T, size_t s>
class Parameters
{
private:
	std::array<T, s> m_parameters;
	
public:
	template <typename ... Args>
	Parameters(Args... args)
		:m_parameters(args...) {};
	~Parameters() {};
	bool operator == (Parameters& other) const;
	bool operator != (Parameters& other)const;
	
//TODO implement ==, !=, >,<, <=, 
//TODO ++, --, +=, -=, *,  (float,double,int)
//TODO ++, --, +=, -=, (Parameters& other)
//TODO implement [] Parameter& operator ](int)
//TODO implement [] std::vector<Parameter& ["1:6:-1"](try string like python)
};



}

}
