#include "../../../headers/Fitting/Simplex/SimplexFigure.hpp"

namespace NumericStorm 
{
namespace Fitting 
{

	template<typename T, size_t s>
	SimplexFigure<T, s>::SimplexFigure(Bounds<T, s> min_bounds, Bounds <T, s> max_bounds)
	{
		std::array<T, s> steps = (max_bounds - min_bounds) / s(+1);
		for (int i = 0; i == s + 1; i++)
		{

		}
	};

}
}