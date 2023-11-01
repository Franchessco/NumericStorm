#pragma once
#include <array>

namespace NumericStorm {

namespace Fitting 
{

	template <typename T, size_t s>
	class MeasuringFunctions
	{
	private:
		MeasuringFunctions() {}
		~MeasuringFunctions() {}
	public:
		static double chi2_norm(std::array<T, s>& mother, std::array<T, s>& child);
		static double min_max_norm(std::array<T, s>& mother, std::array<T, s>& child);
		static double root_chi2_norm(std::array<T, s>& mother, std::array<T, s>& child);
		static double mean_absolut_norm(std::array<T, s>& mother, std::array<T, s>& child);
		
		//todo implement measuring funcitons based on mapping and streams
	};
}
}