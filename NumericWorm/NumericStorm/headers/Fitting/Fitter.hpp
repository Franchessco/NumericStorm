#pragma once

#include "Parameters.hpp"
#include "Data.hpp"

namespace NumericStorm {

	typedef Data<double> (*func)(Parameters& param);
	class Fitter
	{
	private:
		Parameters m_proposalParameters;
	protected:
		Parameters m_fittedParameters;
		Data<double> m_data ;
		func m_model;
		Fitter(func model, Data<double>& data,Parameters proposalParameters)
			:m_model(model), m_data(data),m_proposalParameters(proposalParameters){};
	
	public:
		virtual Parameters getParameters() const = 0;
		virtual void setParameters(Parameters param) = 0;
		virtual Data<double> model(Parameters param) { return m_model(param); };
		
	};

}