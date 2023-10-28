#pragma once
#include <array>

namespace NumericStorm 
{

template <typename T, size_t s>

class Bounds
{
private:
	std::array<T, s> m_Bounds;

public:
	template <typename ... Args>
	Bounds(Args... args)
		:m_Bounds(args...) {};
	~Bounds() {};
};

}





