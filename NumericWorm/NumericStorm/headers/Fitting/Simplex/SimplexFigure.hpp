#pragma once
#include"../Parameters.hpp"
#include"../Bounds.hpp"
#include <array>

namespace NumericStorm 
{
namespace Fitting 
{

template <typename T,size_t s>
class SimplexFigure
{
public:
	SimplexFigure() {};
	SimplexFigure(Bounds<T,s> min_bounds,Bounds<T,s> max_bounds);
	~SimplexFigure() {}
private:
	std::array<T, s + 1> m_vertex;

};

}
}

