#pragma once
#include <memory>

#include "Parameters.hpp"
#include "Data.hpp"

namespace NumericStorm {
namespace Fitting {


template<typename T_d, typename T_p, size_t s_p, size_t s_d>
//typedef Data<T_d,s_d> (*func)(const Parameters<T_p,s_p>& param);
class Fitter
{
protected:
	typedef Data<T_d, s_d>(*func)(const Parameters<T_p, s_p>& param);
	Parameters<T_p, s_p> m_fittedParameters;
	std::unique_ptr<Data<T_d, s_d>> m_data;
	func m_model;
	Fitter() {};
	Fitter(func model, const Data<T_d, s_d>& data)
		:m_model(model), m_data(data), m_fittedParameters(nullptr) {};
	Fitter(Fitter& other) {};  //TODO write this constructors(copy)
	Fitter(Fitter&& other) {}; //TODO write this constructors(move) 
	~Fitter() {}; //! I don't have to free memory, because smart pointers

	public:
	virtual Data<T_d, s_d> model(Parameters<T_p, s_p> param) const
	{
	return m_model(param);
	};

		virtual Parameters<double, s_p> fit() override = 0;
		virtual Parameters<double, s_p> minimize() override = 0;
	};

	}
}