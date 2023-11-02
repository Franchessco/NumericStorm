#pragma once
#include <memory>

#include "Parameters.hpp"
#include "Data.hpp"

namespace NumericStorm {
namespace Fitting {


template<typename T_d,typename T_p,size_t s_p,size_t s_d>

//typedef Data<T_d,s_d> (*func)(const Parameters<T_p,s_p>& param);
class Fitter
{
	typedef std::unique_ptr<Data<T_d,s_d>> (*func)(const Parameters<T_p,s_p>& param);
private:
	Parameters<T_p,s_p> m_proposalParameters;
protected:
	Parameters<T_p,s_p> m_fittedParameters;
	std::unique_ptr<Data<T_d,s_d>> m_data;
	func m_model;
	Fitter() {};
	Fitter(func model, Data<T_d,s_d>& data,Parameters<T_p,s_p> proposalParameters)
		:m_model(model), m_data(&data),m_proposalParameters(proposalParameters){};
	Fitter(Fitter& other) {};  //TODO write this constructors(copy)
	Fitter(Fitter&& other) {}; //TODO write this constructors(move) 
	~Fitter() {}; //! I don't have to free memory, because smart pointers

public:
	virtual Parameters<T_p,s_p> getParameters() const = 0;
	virtual void setParameters(Parameters<T_p,s_p> param) = 0;
	virtual std::unique_ptr<Data<T_d,s_d>> model(Parameters<T_p,s_p> param) const 
		{ return m_model(param); };
	/*
	
	virtual Data<double> model(Parameters<double,s_p> param) const
	{
		return m_model(param);
	};
	*/
	virtual Parameters<double,s_p> fit() = 0;
	virtual Parameters<double,s_p> minimize() = 0;
};

}
}