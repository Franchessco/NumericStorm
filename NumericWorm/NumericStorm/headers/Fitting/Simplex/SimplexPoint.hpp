#pragma once
#include "../Parameters.hpp"
namespace NumericStorm {
namespace Fitting 
{

template<typename T, size_t s>
class SimplexPoint :public Parameters
{
private:
	double m_error;
public:
	template <typename Args... args>
	SimplexPoint() {};
	SimplexPoint(const Parameters<T,s>& other)
		:Parameters(std::move(other));
	void PointToBound(const Bounds<T, s>& other,std::string type);
	
	
};


}

}
}

