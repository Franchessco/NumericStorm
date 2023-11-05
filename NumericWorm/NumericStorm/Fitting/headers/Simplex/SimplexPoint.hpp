#pragma once
#include "../Parameters.hpp"
#include "../MeasuringFunctions.hpp"
namespace NumericStorm {
namespace Fitting 
{

template<typename T, size_t s>
class SimplexPoint :public Parameters<T,s>
{
private:
	double m_error;
	bool operator < (const Bounds<T,s>& other);
	bool operator > (const Bounds<T,s>& other);

public:
	double getError()
	{return m_error;};


	// Comparacent
	bool operator < (const SimplexPoint<T, s>& other)
	{return true ? m_error < other.getError() : false;};
	
	bool operator > (const SimplexPoint<T,s>& other)
	{return !(m_error < other.getError();)};

	bool operator =< (const SimplexPoint<T, s>& other)
	{return true ? m_error = < other.getError() : false;};

	bool operator <= (const SimplexPoint<T, s>& other)
	{return true ? m_error <= other.getError() : false;};


	// construdtor
	SimplexPoint() {};
	~SimplexPoint() {};
	SimplexPoint(Parameters<T, s> other, double error = nullptr)
		:Parameters<T, s>(std::move(other)), m_error(error) {};

	template <typename... Args>
	SimplexPoint(double error = 100.0,Args... args) 
		: Parameters<T, s>(args...),m_error(error) {}

	void setError(unsigned double error) { m_error = error; };

	template <typename T_d,size_t s_d>
	using Data_ = Data<T_d, s_d>;
	typedef double(*error_func)(cosnt Data_& mother, const Data_& child);
	unsigned double claculateError(const Data<T_d,s_d>& data,error_func error_function);


	void setPointToBound(const Bounds<T, s>& min_bounds, const Bounds<T, s>& max_bounds);

	
	
};


}
}


