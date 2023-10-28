#pragma once
#include <array>

namespace NumericStorm {


template <typename T,size_t s>
class MeasuringFunctions
{
private:
	MeasuringFunctions() {}
	~MeasuringFunctions() {}
public:
	static double chi2_norm(std::array<T, s>& mother, std::array<T, s>& mother);
	static double max_norm(std::array<T, s>& mother, std::array<T, s>& mother);

};


}

