#pragma once

#include "Fitting/Fitter.hpp"
#include "../MeasuringFunctions.hpp"
#include "Fitting/Bounds.hpp"

#include <string>
#include <memory>


namespace NumericStorm 
{
namespace Fitting 
{


template<typename T_d,typename T_p, size_t s_d,size_t s_p>
class SimplexSolver: public Fitter
{
	//using Data_t = Data<T_d, s_d>;
	typedef error_method_func_ = double(*error_method_func)(const Data<T_d, s_d>& mother, const Data<T_d, s_d>& child);
	
private:
	//double m_max_error;
	//auto m_error_method;
	//std::string m_method_error;
	SimpelxFigure<T_p, s_p+1> vertex;
public:
	SimplexSolver() 
		:Fitter(){};

	SimplexSolver(
		func model,
		std::uniq_ptr<Data<T_d,s_d>& data>,
		Bounds<T_p, s_p>  lowerBounds,Bounds<T_p, s_p> upperBounds)
		:Fitter(model, data),vertex(lowerbounds,upperbounds){}

	~SimplexSolver() {};
	virtual Parameters<T_p,s_p> fit(double max_error,error_method_func_ error_method = nullptr,
		std::string method_error = "chi2" ) override = 0
	
};
}

}

