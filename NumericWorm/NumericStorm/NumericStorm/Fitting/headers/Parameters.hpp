#pragma once
#include <array>
#include <string>

namespace NumericStorm {
namespace Fitting 
{
template <typename T_p,size_t s_p>
class Parameters
{
public:
	template<class ... Args>
	Parameters(Args... args)
		:m_parameters{ (T_p)args... } {}
		
	Parameters(std::array<T_p,s_p> parameters)
		:m_parameters(parameters) {}
	~Parameters() {}
	
	std::array<T_p, s_p> getParamters() 
	{ return m_parameters; }

public:
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
	bool operator ==(const Parameters<T_p, s_p>& other) const
	{
		return m_parameters == other;
	}
	bool operator ==(const std::array<T_p, s_p>& other) const
	{
		return m_parameters == other;
	}
private:
	std::array<T_p,s_p> m_parameters;

};
}
}

