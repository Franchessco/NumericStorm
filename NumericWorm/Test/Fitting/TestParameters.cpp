#include "pch.h"
#include <string>

using namespace NumericStorm::Fitting;

TEST(PARAMETERS, getParameters)
{
    // Test data
    std::array<double, 2> a1{ 1, 2.2 };
    std::array<int, 2> a2{ 1, 2 };
    std::array<std::string, 3> a3{ "Parameters", "Testing", "something" };
    // Prepare data
    
    Parameters<double, 2> p1(1.0, 2.2);
    Parameters<int, 2> p2(1, 2);
    Parameters<std::string, 3> p3("Parameters", "Testing", "something");
    

    Parameters<double, 2> p4(a1);
    Parameters<int, 2> p5(a2);
    Parameters<std::string, 3> p6(a3);
    double d4 = p4[0];
    int d5 = p5[0];
    std::string d6 = p6[0];
    
    // Success - Using EXPECT_EQ to test equality
    /*EXPECT_EQ(p1.getParamters(), a1);
    EXPECT_EQ(p2.getParamters(), a2);
    EXPECT_EQ(p3.getParamters(), a3);*/
    EXPECT_EQ(p4.getParamters(), a1);
    EXPECT_EQ(p5.getParamters(), a2);
    EXPECT_EQ(p6.getParamters(), a3);

    // Failure - Using EXPECT_NE to test inequality
    //EXPECT_NE(p4.getParamters(), a3);
    //EXPECT_NE(p5.getParamters()[0], a1[0]);
    //EXPECT_NE(p6.getParamters()[0], a2[0]);
}


//TEST(PARAMETERS, indexOperator) 
//{
//	Parameters<double, 2> p(1, 2);
//	EXPECT_EQ(p[0],1);
//	FAIL(p[2]);
//
//}