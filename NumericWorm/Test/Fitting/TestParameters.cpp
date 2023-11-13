#include "pch.h"
#include <string>
#include <array>

using namespace NumericStorm::Fitting;

struct TestParameters:public testing::Test
{
public:
    // Test data
    std::array<double, 2> d1{ 1, 2.2 };
    std::array<int, 2> d2{ 1, 2 };
    std::array<std::string, 3> d3{ "Parameters", "Testing", "something" };
    Parameters<int, 2> p1{ 1, 2 };
    Parameters<double, 2> p2{1.0, 2.2};
    Parameters<std::string, 3> p3{"Parameters", "Testing", "something"};

    Parameters<double, 2> p4{d1};
    //Parameters<int, 2> p5(d2);
    //Parameters<std::string, 3> p6(d3);

};



TEST_F(TestParameters, constructingParameters) {
    int a = p1.getParamters()[0];
    EXPECT_EQ(a, 1);
}


//TEST(PARAMETERS, indexOperator) 
//{
//	Parameters<double, 2> p(1, 2);
//	EXPECT_EQ(p[0],1);
//	FAIL(p[2]);
//
//}