#include "../../headers/Simplex/SimplexPoint.hpp"
#include "../../headers/Bounds.hpp"

namespace NumericStorm
{
	namespace Fitting
	{

		//! Private Method
		template<typename T, size_t s>
		bool SimplexPoint<T, s>::operator > (const Bounds& other)
		//! Warning this method may change the object 
		{
			for (int i = 0; i < s; i++)
			{
				if (m_parammeters[i] > other[i])
					m_parammeters[i] = other[i];
				else
					continue;
			}
			return false;
		};

		template<typename T, size_t s>
		bool SimplexPoint<T, s>::operator < (const Bounds& other1)
			//! Warning this method may change the object 
		{
			for (int i = 0; i < s; i++)
			{
				if (m_parammeters[i] < other[i])
					m_parammeters[i] = other[i];
				else
					continue;
			}
			return false;
		}


		unsigned double claculateError(const Data<T_d, s_d>& data, error_funcerror_function)
		{

			return 0.0;
		}

		//! public methods
		template<typename T, size_t s>
		void setPointToBound(const Bounds<T, s>& min_bounds, const Bounds<T, s>& max_bounds)
		{
			bool min_bounds = *this < min_bounds;
			bool max_bounds = *this > max_bounds;
		}

}
}