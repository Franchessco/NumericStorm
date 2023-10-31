#include "Fitting/Parameters.hpp"
#include "Fitting/Bounds.hpp"
namespace NumericStorm 
{
namespace Fitting 
{

	template<typename T, size_t s>
	inline bool Parameters<T, s>::operator==(Parameters& other) const
	{
		for (int i = 0; i < s; i++)
			if (m_parameters[i] != other[i])
				return false;
		return true;
	}
	
	template<typename T, size_t s>
	inline bool Parameters<T, s>::operator!=(Parameters& other) const
	{
		return !(*this == other)
	}



}
}