

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
class Data {
public:
	std::shared_ptr<std::array<double, 5>> m_data;

	// Constructor
	Data(std::shared_ptr<std::array<double, 5>> data) : m_data(data) {}

	void add5() {
		for (auto& i : *m_data) {
			i += 5;
		}
	}
};
int add5(int x) { return x + 5; }
void add5ref(int& x) {  x+5; }
int* add5refretptr(int& x) { int z = x + 5; return &z; }
int add5ptr(int* x) { int z = *x + 5; return z; }


int main() {
	/*
	std::array<double, 5> data{ 1, 2, 3, 4, 5 };
	std::shared_ptr<std::array<double, 5>> data_ptr = std::make_shared<std::array<double, 5>>(data);

	Data dataClass(data_ptr);

	for (auto i : *dataClass.m_data) {
		std::cout << i << std::endl;
	}

	// Access the shared array via the shared pointer
	dataClass.add5();

	// Display the modified values through the class member's shared pointer
	for (auto i : *dataClass.m_data) {
		std::cout << i << std::endl;
	}
	//? initialize data to fit;;
	*/
	/*using const_vector = const std::vector<double>;
	using vector_shared = std::shared_ptr< std::vector<double>>;
	using const_shared_vector = std::shared_ptr<const_vector>;

	const_vector v{ 1,2,3,4,5,6 };
	const_shared_vector pv_1 = std::make_shared<const_vector>(v);
	vector_shared pv_2 = std::make_shared<std::vector<double>>();
	(*pv_2).resize(5);
	std::cout << (*pv_2)[0] << std::endl;
	*/
	//! std::shared_ptr<Fitting::Data<double,256>> dataToFit = std::make_shared<Fitting::Data<double,256>(Fitting::Data(x,y));
	//! #typedef std::uniq_ptr<Data<double,256>> (*my_model)(const Parameters<double,4> param);
	//! my_model = {my model function};
	using namespace NumericStorm::Fitting;

	//int x = 9;
	//int* x_p = &x;
	//std::cout << "x:" << x << std::endl;
	//std::cout << "x_p:" << x_p << std::endl;
	//std::cout << "&x:" << &x << std::endl;
	//std::cout << "*x_p:" << *x_p << std::endl;
	//std::cout << "-----------------" << std::endl;
	//int y = add5(x);
	////int y_ref = add5ref(x);
	////std::cout << "y_ref:" << y_ref << std::endl;
	//int* yref = add5refretptr(x);
	//int yptr = add5ptr(x_p);

	//std::cout << "x:" << x << std::endl;
	//std::cout << "x_p:" << x_p << std::endl;
	//std::cout << "&x:" << &x << std::endl;
	//std::cout << "*x_p:" << *x_p << std::endl;

	//std::cout << "--------------" << std::endl;
	//std::cout << "y:" << y << std::endl;
	//std::cout << "yref:" << yref << std::endl;
	//std::cout << "yptr:" << yptr << std::endl;
	//
	//std::cout << "--------------" << std::endl;
	//std::cout << "&yref:" << &yref << std::endl;
	//std::cout << "*yref:" << *yref << std::endl;
	//std::cout << "--------------" << std::endl;
	//std::cout << "&yptr " << &yptr << std::endl;
	Parameters<2,int> p1{ 1, 2 };
	Parameters<2> p2{ 1.0, 2.2 };

	std::array<int,2> d1{ 1, 2 };
	std::array<double, 2> d2{ 1.0, 2.2 };
	Parameters<2,int> p4{ d1 };
	Parameters<2> p5{ d2 };
	//? settign bounds
	//! Bounds min_bounds = Bounds(x_min,y_min,..);
	//! Bounds max_bounds = Bounds(x_min,y_min,..);
	
	//? initialize Solver
	//TODO Create abstract Solver
	//TODO Create Abstract SimplexSolver
	//TODO Create Simple SimplexSolver
	//! Parameters proposal_parameters = Parameters(a,b,c,d,....);
	//! Fitter fitter = SimpleSimplex(my_model,dataToFit,min_bounds,max_bounds,);

	//? setting max error
	//! double max_error = 10;
	//? fit data
	//! fitter.fit(max_error);

	//std::array<double, 2> d1{ 2, 2 };
	//NumericStorm::Fitting::Parameters<double, 2> param(1, 2);
	//NumericStorm::Fitting::Parameters<double, 2> param2{d1};
	//std::cout << param.getParameters()[0] << std::endl;
	//std::cout << param[0] << std::endl;
	//param[0] = 10;
	//std::cout << param[0] << std::endl;	

	//bool b1 = (param2 == d1);
	//bool b2 = (param == NumericStorm::Fitting::Parameters<double, 2>{10, 2});
	//std::cout << b1 << std::endl;
	//std::cout << b2 << std::endl;
	return 0;
}