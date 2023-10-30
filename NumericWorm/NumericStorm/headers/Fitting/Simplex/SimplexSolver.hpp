#pragma once

#include "Fitting/Fitter.hpp"
#include "../MeasuringFunctions.hpp"
#include "Fitting/Bounds.hpp"

#include <string>


namespace NumericStorm 
{
namespace Fitting {


template<typename T_d,typename T_p, size_t s_d,size_t s_p>
class SimplexSolver: public Fitter
{
	using Data_t = Data<T_d, s_d>;
	using error_method_func_ = double(*error_method_func)(const Data_t& mother, const Data_t& child);
	
private:
	double m_max_error;
	auto m_error_method;
	std::string m_method_error;
	Bounds m_loweBounds;
	Bounds m_upperBounds;
public:
	SimplexSolver() :Fitter(){};

	SimplexSolver(
		func model,
		Data_t& data,
		Parameters<T_p, s_p> proposalParameters,
		double max_error,
		Bounds lowerBounds;
		Bounds upperBounds;
		error_method_func_ error_method = nullptr,
		std::string method_error = "chi2",
		)

	:Fitter(model,data,proposalParameters), m_max_error(max_error),
	m_error_method(error_method), m_method_error(method_error),
	m_lowerBounds(lowerBounds),m_upperBounds(upperBounds){};

	~SimplexSolver() {};

};
}

}

