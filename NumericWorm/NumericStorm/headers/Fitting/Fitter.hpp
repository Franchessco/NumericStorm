#pragma once
#include <memory>

#include "Parameters.hpp"
#include "Data.hpp"

namespace NumericStorm {
template<size_t s>

// typedef Data<double> (*func)(const Parameters<double,s><double,>& param);
class Fitter
{
	typedef std::unique_ptr<Data<double>> (*func)(const Parameters<double,s>& param);
private:
	Parameters<double,s> m_proposalParameters;
protected:
	Parameters<double,s> m_fittedParameters;
	std::unique_ptr<Data<double>> m_data;
	func m_model;
	Fitter() {};
	Fitter(func model, Data<double>& data,Parameters<double,s> proposalParameters)
		:m_model(model), m_data(&data),m_proposalParameters(proposalParameters){};
	Fitter(Fitter& other) {};
	Fitter(Fitter&& other) {};
	~Fitter() {};

public:
	virtual Parameters<double,s> getParameters() const = 0;
	virtual void setParameters(Parameters<double,s> param) = 0;
	virtual std::unique_ptr<Data<double>> model(Parameters<double,s> param) const 
		{ return m_model(param); };
	/*
	
	virtual Data<double> model(Parameters<double,s> param) const
	{
		return m_model(param);
	};
	*/
	virtual Parameters<double,s> fit() = 0;
	virtual Parameters<double,s> minimize() = 0;
};

}