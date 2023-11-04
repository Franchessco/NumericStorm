

#include "../headers/Apllication.hpp"

int main()
{
	//? initialize data to fit
	
	//! std::uniq_ptr<Data<double,256>> dataToFit = std::make_uniq<Data<doulbe,256>(Data(x,y));
	//! #typedef std::uniq_ptr<Data<double,256>> (*my_model)(const Parameters<double,4> param);
	//! my_model = {my model function};
	
	//? settign bounds
	//! Bounds min_bounds = Bounds(x_min,y_min,..);
	//! Bounds max_bounds = Bounds(x_min,y_min,..);
	//? initialize Solver
	//! Parameters proposal_parameters = Parameters(a,b,c,d,....);
	//! Fitter fitter = SimpleSimplex(my_model,dataToFit,min_bounds,max_bounds,);
	
	//? setting error functions
	//! std::string error_function = "chi2";
	//? fit data
	//! fitter.fit();
	
	NumericStorm::PrintMessage();
	return 0;
}