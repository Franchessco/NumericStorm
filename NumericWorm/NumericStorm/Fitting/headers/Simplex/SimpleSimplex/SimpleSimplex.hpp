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
	Parameters<T_p, s_p> fit(double max_error, error_method_func_ = nullptr, std::string method_error);
	SimpleSimplex()
		:SimplexSolver() {};
	SimpelSolver(func model, Data<T_d, s_d> data,
		Bounds<T_p, s_p> lowerBounds,Bounds<T_p,s_p> upperBounds)
		: {}
};
}

}



