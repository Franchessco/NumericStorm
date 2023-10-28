#pragma once
#include <vector>

namespace NumericStorm
{
template <typename T>

class Data
{
protected:
	std::vector<T> m_x;
	std::vector<T> m_y;
	Data(const std::vector<T>& x, const std::vector<T>& y)
		:m_x(x), m_y(y) {};

public:
	std::vector<T> getX() const { return m_x; };
	std::vector<T> getY() const { return m_y; };
	friend class Fitter;

	virtual setX(std::vector<T> x){return m_x};// do more than setting, also checking the condition
	virtual sety(std::vector<T> y){return m_y};// do more than setting, also checking the condition
};


}
