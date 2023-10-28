#pragma once

#include "Fitting/Fitter.hpp"
namespace NumericStorm 
{
template<size_t s>
class SimplexSolver: public Fitter

{
private:
/// <summary>
/// 
/// </summary>
public:
	SimplexSolver() :Fitter(){};

	SimplexSolver(func model, Data<double>& data, Parameters<double,s> proposalParameters) 
	:Fitter(model,data,proposalParameters){};

	~SimplexSolver() {};

};

}

