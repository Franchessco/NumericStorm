#pragma once

#include "../SimplexSolver.hpp"


namespace NumericStorm 
{
namespace Fitting 
{
template<typename T_d, typename T_p, size_t s_d, size_t s_p>
class SimpleSimplex : public SimplexSolver
{
public:
	typedef error_method_func_ = double(*error_method_func)(const Data<T_d, s_d>& mother, const Data<T_d, s_d>& child);
	SimpleSimplex()
		:SimplexSolver() {};
	SimpelSolver(func model, Data<T_d, s_d> data,
		Bounds<T_p, s_p> lowerBounds,Bounds<T_p,s_p> upperBounds)
		: {}
};
}}



