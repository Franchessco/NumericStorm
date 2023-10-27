#pragma once

#include "Parameters.hpp"
#include "Data.hpp"

namespace NumericStorm {

	typedef Data (*func)(Parameters& param);

	class Fitter
	{
	protected:
		Parameters m_fittedParameters;
		Data m_data;
		func m_model;
		Fitter(func model, Parameters& data)
			:m_model(model), m_data(data){};
	
	public:
		virtual Parameters getParameters() const = 0;
		virtual void setParameters(Parameters param) = 0;
		Data model(Parameters& param) { return m_model(param); };
	};

}