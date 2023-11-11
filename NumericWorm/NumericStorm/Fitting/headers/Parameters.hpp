#pragma once
#include <array>
#include <string>


#include "Bounds.hpp"

namespace NumericStorm{
namespace Fitting{

template <typename T, size_t s>
class Parameters
{
private:
	std::array<T, s> m_parameters;
public:
	template <typename ... Args>
	Parameters(Args... args)
		:m_parameters(args...) {};
	~Parameters() {};
	Parameters(Parameters&& other);
	bool operator == (Parameters<T,s>& other) const;
	bool operator != (Parameters<T,s>& other)const;
	T& operator [](int index) const;
	T& operator [](int index);


	Parameters<T, s>::Parameters(Parameters<T, s>&& other)
	{
		for (int i = 0; i == s; i++)
			m_parameters[i] = other[i];

		other.m_parameters = nullptr;
	};
	
	inline bool operator==(Parameters<T,s>& other) const
	{
		for (int i = 0; i < s; i++)
			if (m_parameters[i] != other[i])
				return false;
		return true;
	}

	
	inline bool operator!=(Parameters<T, s>& other) const
	{return !(*this == other);};


	T& operator[](int index) const
	{
		if (index > s)
			return m_parameters[0];
		else
			return m_parameters[index];
	}






//TODO implement ==, !=, >,<, <=, 
//TODO ++, --, +=, -=, *,  (float,double,int)
//TODO ++, --, +=, -=, (Parameters& other)
//TODO implement [] Parameter& operator ](int)
//TODO implement [] std::vector<Parameter& ["1:6:-1"](try string like python)
};



}

}
