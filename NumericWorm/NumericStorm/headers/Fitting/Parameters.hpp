#pragma once
#include <array>


namespace NumericStorm{
template <typename T,size_t s>

class Parameters
{
	
private: 
	std::array<T,s> m_parameters;
public:
	template <typename ... Args>
	Parameters(Args... args) 
		:m_parameters(args...) {};
	~Parameters() {};

	bool operator == (const Parameters& other) const 
	{
	}
		//TODO implement ==, !=, >,<, >=, <=, 
		//TODO ++, --, +=, -=, *, / (for float,double,int)
		//TODO ++, --, +=, -=, (cosnt Parameters& other)
		//TODO implement [] operator Parameter& operator [](int)
		//TODO implement [] operator std::vector<Parameter&> operator ["1:6:-1"](try string like python)
};

}
