#include "../headers/Fitting/Fitting.hpp"
#include "../headers/Fitting/Bounds.hpp"
#include "../headers/Fitting/Parameters.hpp"
namespace NumericStorm
{
namespace Fitting 
{
	template<typename T, size_t s>
	Parameters<T, s>::Parameters(Parameters&& other)
	{
		m_paramters = std::move(other.m_parameters);
		other.m_parameters = nullptr;
	}
	template<typename T, size_t s>
	inline bool Parameters<T, s>::operator==(Parameters& other) const
	{
		for (int i = 0; i < s; i++)
			if (m_parameters[i] != other[i])
				return false;
		return true;
	}
	
	template<typename T, size_t s>
	bool Parameters<T, s>::operator!=(Parameters& other) const
	{
		return !(*this == other)
	}



}
}