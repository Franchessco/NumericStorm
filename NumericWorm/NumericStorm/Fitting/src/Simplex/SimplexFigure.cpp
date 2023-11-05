#include "../../headers/Simplex/SimplexFigure.hpp"


namespace NumericStorm 
{
namespace Fitting 
{
template <typename T, size_t s>;
SimplexFigure<T, s + 1>::SimplexFigure(Bounds<T, s> max_bounds,Bounds<T,s> min_bounds) 
{
int devider = 1 / (s + 1);
Parameters<T, s> step = (max_bounds - min_bounds) * devider;
for (int i = 0; i < s + 1; s++) 
	m_vertex[i] = min_bounds + i * step;

};



}
}