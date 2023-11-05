#pragma once
//#include"../Parameters.hpp"
//#include"../Bounds.hpp"
#include "SimplexPoint.hpp"

#include <algorithm>
#include <array>

namespace NumericStorm 
{
namespace Fitting 
{

template <typename T,size_t s>
class SimplexFigure
{
public:
	//SimplexFigure() {};
	SimplexFigure(Bounds<T,s> min_bounds,Bounds<T,s> max_bounds);
	~SimplexFigure() {}
private:
	std::array<SimplexPoint, s + 1> m_vertex;
	void sort() 
	{std::sort(m_vertex.begin(), m_vertex.end());};
};

}
}

