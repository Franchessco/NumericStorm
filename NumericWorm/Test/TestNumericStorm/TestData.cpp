#include "pch.h"
using namespace NumericStorm;

struct TestData :public testing::Test
{


};


struct CreatingData:public testing::Test 
{

	using const_vector = const std::vector<double>;
	using vector_shared = std::shared_ptr< std::vector<double>>;
	using const_shared_vector = std::shared_ptr<const_vector>;

	const_vector v1{1,2,3,4,5,6};
	const_vector v2{7,8,9};

	const_shared_vector pv_1 = std::make_shared<const_vector>(v1);
	const_shared_vector pv_2 = std::make_shared<const_vector>(v2);
	
	//vector_shared pv_2 = std::make_shared<std::vector<double>>();
	
};
TEST(CreatingData, CreatingBasedOnArray) 
{
	std::vector<double> t1{ 1,2,3,4,5,6 };
	std::vector<double> t2{ 7,8,9 };
	std::vector<std::vector<double>> t{ t1,t2 };
	Data<double> d1(t1,t2);
	auto p1 = d1.getData();
	EXPECT_EQ(p1, t);

};
TEST(CreatingData, CreatingBasedOnArgs) {};

//TEST_F(TestData, GetData) {};
//TEST_F(TestData, Constdata) {};
//TEST_F(TestData, IteratingThroughData) {};

