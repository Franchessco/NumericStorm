#pragma once
#include <array>
#include <string>
#include <iostream>

namespace NumericStorm {
namespace Fitting 
{
template <size_t s_p, typename T_p = double,size_t s_o=s_p,typename T_o = double>
class Parameters
{
public:
	template<class ... Args>
	Parameters(Args... args)
		:m_parameters{ (T_p)args... }
		{}
		
	Parameters(std::array<T_p,s_p> parameters)
		:m_parameters(parameters) {}
	~Parameters() {}
	
	std::array<T_p, s_p> getParameters()
	{ return m_parameters; }

	std::array<T_p, s_p> getParameters() const
	{return m_parameters;}

	T_p& operator[](int index) 
	{
		if (index >= s_p) { return m_parameters[0];}
		return m_parameters[index];
	}
	const T_p& operator[](int index) const
	{
		if (index >= s_p) { return m_parameters[0]; }
		return m_parameters[index];
	}

	bool operator ==(const Parameters<s_p,T_p>& other) const
	{
		return m_parameters == other.getParameters();
	}
	bool operator ==(const std::array<T_p,s_p>& other) const
	{
		return m_parameters == other;
	}

	Parameters<s_p, T_p>& operator = (const Parameters<s_o, T_o>& other) 
	{
		if (this == &other) 
			return *this;
		m_parameters = other.getParameters();
		return *this;
	}

	Parameters<s_p, T_p>& operator += (const Parameters<s_o, T_o>& other) 
	{	
		for (size_t i = 0; i < s_p; i++)
			m_parameters[i] += other[i];
		return *this;
	};
	Parameters<s_p, T_p>& operator -= (const Parameters<s_o, T_o>& other) 
	{	
		for (size_t i=0; i <s_p;i++)
			m_parameters[i] -= other[i];
		return *this;
	};

	Parameters<s_p, T_p>& operator += (double& other) 
	{
		for (size_t i = 0; i < s_p; i++)
			m_parameters[i] += other;
		return *this;
	};
	Parameters<s_p, T_p>& operator -= (double& other)
	{
		for (size_t i = 0; i < s_p; i++)
			m_parameters[i] -= other;
		return *this;
	};
	Parameters<s_p, T_p>& operator *= (double& other)
	{
		for (size_t i = 0; i < s_p; i++)
			m_parameters[i] *= other;
		return *this;
	};
	Parameters<s_p, T_p>& operator /= (double& other)
	{
		for (size_t i = 0; i < s_p; i++)
			m_parameters[i] /= other;
		return *this;
	};

	Parameters<s_p, T_p> operator + (const Parameters<s_o, T_o>& other) 
		{return *this += other;};
	Parameters<s_p, T_p> operator - (const Parameters<s_o, T_o>& other) 
		{ return *this -= other; };
	Parameters<s_p, T_p> operator + (double& other) {return *this += other; };
	Parameters<s_p, T_p> operator - (double& other) {return *this -= other; };
	Parameters<s_p, T_p> operator * (double& other) {return *this *= other; };
	Parameters<s_p, T_p> operator / (double& other) {return *this /= other; };

protected:
	std::array<T_p,s_p> m_parameters;

};
}
}

