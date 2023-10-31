#include "../headers/Fitting/MeasuringFunctions.hpp"

namespace NumericStorm{
namespace Fitting {


template<typename T, size_t s>
double MeasuringFunctions<T, s>::chi2_norm(std::array<T, s>& mother, std::array<T, s>& child)
{
	return 0.0;
}

template<typename T, size_t s>
double MeasuringFunctions<T, s>::min_max_norm(std::array<T, s>& mother, std::array<T, s>& child)
{
	return 0.0;
}

template<typename T, size_t s>
double MeasuringFunctions<T, s>::root_chi2_norm(std::array<T, s>& mother, std::array<T, s>& child)
{
	return 0.0;
}

template<typename T, size_t s>
double MeasuringFunctions<T, s>::mean_absolut_norm(std::array<T, s>& mother, std::array<T, s>& child)
{
	return 0.0;
}

}
}

