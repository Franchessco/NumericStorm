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
	template<typename ... Args>
	Parameters(Args ...args)
		:m_parameters{ args... } {}
	Parameters(std::array<T_p,s_p> parameters)
		:m_parameters(parameters) {}
	~Parameters() {}
	std::array<T_p, s_p> getParamters() { return m_parameters; }
	//T_p& operator [](int index) const;
public:
	T_p& operator[](int index) 
	{
		if (index >= s_p) { return m_parameters[0];}
		return m_parameters[index];
	}
private:
	std::array<T_p, s_p> m_parameters;

};
}
}

