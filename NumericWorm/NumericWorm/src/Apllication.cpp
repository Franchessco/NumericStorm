

#include "../headers/Apllication.hpp"

//template<typename... Ts>
//int* func(Ts... args) {
//	const int size = sizeof...(args);
//	int* res = new int[size] { args... };  
//
//	for (int i = 0; i < size; i++) {
//		std::cout << res[i] << std::endl;
//	}
//
//	return res;  // Return the pointer to the allocated array
//}

int main() {
	//int* p = func(1, 2, 3, 4, 5);

	// Ensure to delete the allocated array to avoid memory leaks
	//delete[] p;
	/*
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
	*/	
	
	NumericStorm::Fitting::Parameters<double,2> param(1, 2);
	std::cout << param.getParamters()[0] << std::endl;
	std::cout << param[0] << std::endl;
	param[0] = 10;
	std::cout << param[0] << std::endl;	
	return 0;
}