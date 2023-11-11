

#include "../headers/Apllication.hpp"

int main()
{
	{
		using namespace NumericStorm;
			//? initialize data to fit;;

			//! std::shared_ptr<Fitting::Data<double,256>> dataToFit = std::make_shared<Fitting::Data<double,256>(Fitting::Data(x,y));
			//! #typedef std::uniq_ptr<Data<double,256>> (*my_model)(const Parameters<double,4> param);
			//! my_model = {my model function};

			//? settign bounds
			//! Bounds min_bounds = Bounds(x_min,y_min,..);
			//! Bounds max_bounds = Bounds(x_min,y_min,..);
			//? initialize Solver
			//! Parameters proposal_parameters = Parameters(a,b,c,d,....);
			//! Fitter fitter = SimpleSimplex(my_model,dataToFit,min_bounds,max_bounds,);

			//? setting max error 
			//! double max_error = 10;
			//? fit data
			//! fitter.fit(max_error);
	}
	
	NumericStorm::PrintMessage();
	return 0;
}