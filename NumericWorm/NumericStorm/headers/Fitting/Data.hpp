#pragma once
#include <array>

namespace NumericStorm
{ 
namespace Fitting 
{

template <typename T,size_t s>

class Data
{
protected:
	std::array<T,s> m_x;
	std::array<T,s> m_y;
	Data(const std::array<T,s>& x, const std::array<T,s>& y)
		:m_x(x), m_y(y) {};

public:
	std::array<T,s> getX() const { return m_x; };
	std::array<T,s> getY() const { return m_y; };
	friend class Fitter;

	void setX(std::array<T,s> x){m_x = x};// do more than setting, also checking the condition
	void setY(std::array<T,s> y){m_y = y};// do more than setting, also checking the condition
};


}
}

