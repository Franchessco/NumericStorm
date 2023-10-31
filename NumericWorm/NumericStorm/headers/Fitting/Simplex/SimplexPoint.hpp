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
	SimplexPoint() {};
	void PointToBound(const Bounds<T, s>& other,std::string type);
	
	
};


}

}
}

