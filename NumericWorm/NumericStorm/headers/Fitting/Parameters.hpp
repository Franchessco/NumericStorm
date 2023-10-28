#pragma once
#include <array>
#include <memory>

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
};

}
