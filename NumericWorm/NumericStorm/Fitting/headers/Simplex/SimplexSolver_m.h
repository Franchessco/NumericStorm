#pragma once

#include <memory>

#include "SimplexFigure.hpp"
#include "../Fitter.hpp"
#include "../Parameters.hpp"

namespace NumericStorm 
{
namespace Fitting 
{
template <typename T_d, typename T_p, size_t s_d,size_t s_p>
using templatesolver = <T_d, T_p, s_t, s_p>;

class SimpelxSolver : public Fitter  
{


typedef Data<T_d, s_d>(*func)(const Parameters<T_p, s_p>& param);
public:
	SimpelxSolver templatesolver(func model, const Data<T_d, s_d>& data)
		:Fitter templatesolver (model,data) {};
	SimpelxSolver templatesolver (const SimplexSolver& other) {};
	SimpelxSolver templatesolver (const SimplexSolver&& other) {};

	SimpelxSolver ()
		:Fitter() {};
	~SimpelxSolver() {};


private:
	SimplexFigure <T_p,s_p+1> m_vertex;
};

}
}