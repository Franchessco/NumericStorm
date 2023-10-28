#pragma once
#include <memory>

#include "Parameters.hpp"
#include "Data.hpp"

namespace NumericStorm {

typedef std::unique_ptr<Data<double>> (*func)(const Parameters& param);
class Fitter
{
private:
	Parameters m_proposalParameters;
protected:
	Parameters m_fittedParameters;
	Data<double> *m_data ;
	func m_model;
	Fitter(func model, Data<double>& data,Parameters proposalParameters)
		:m_model(model), m_data(&data),m_proposalParameters(proposalParameters){};

public:
	virtual Parameters getParameters() const = 0;
	virtual void setParameters(Parameters param) = 0;
	virtual std::unique_ptr<Data<double>> model(Parameters param) const 
		{ return m_model(param); };
	virtual Parameters fit(const Data<double>& dataToFit) = 0;
};

}