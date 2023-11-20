#include "pch.h"


using namespace NumericStorm::Fitting;

struct TestParameters:public testing::Test
{
public:
    Parameters<2,int> p1{ 1, 2 };
    Parameters<2> p2{ 1.0, 2.2 };
    
    std::array<int, 2> d1{ 1, 2 };
    std::array<double, 2> d2{ 1.0, 2.2 };
    };


struct TestParametersArithmeticAndAssigningOperator : public testing::Test
{
    Parameters<2> p1{ 1, 2 };
    Parameters<2> p2{ 1.0, 2.2 };
    Parameters<2> p3{ 3.0, 4.4 };

    Parameters<2> p1_p_p2{ 2.0,4.2 };
    Parameters<2> p2_p_p3{ 4.0,6.6 };

    Parameters<2> p1_m_p2{ 0,-0.2 };
    Parameters<2> p2_m_p3{ -2,-2.2 };

    double mull = 2,add = 2,sub = 1,div = 2;

    Parameters<2> p1_m{ 2,4 }, p2_m{ 2,4.4 };
    Parameters<2> p1_a{ 3,4 }, p2_a{ 3,4.2 };
    Parameters<2> p1_s{ 0,1 }, p2_s{ 0,1.2 };
    Parameters<2> p1_d{ 0.5,1 }, p2_d{ 0.5,1.1 };
    
};

TEST_F(TestParameters, constructingParametersbylist) 
{
    auto a = p1.getParameters();
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);

    std::array<int, 2> a1{ 1,2 };
    std::array<int, 2> a2{ 1,3 };
    bool b1 = (a == a1),b2= (a==a2);
    
    EXPECT_EQ(b1,1);
    EXPECT_EQ(b2, 0);

}
TEST_F(TestParameters, constructingParametersbyarray) 
{
    Parameters<2,int> p4{ d1 };
    Parameters<2> p5{ d2 };
    bool b1 = (p4.getParameters() == d1), b2 = (p5.getParameters() == d2);
    EXPECT_EQ(b1,1);
    EXPECT_EQ(b2,1);
    

}
TEST_F(TestParameters, operatorequal)
{

    EXPECT_TRUE(p1 == d1);
    EXPECT_TRUE(p2 == d2);
}
TEST_F(TestParameters, gettingParameters) 
{
    int a1;double a2;std::string a3;

    a1 = p1[1];a2 = p2[1];
    int t1 = d1[1]; double t2 = d2[1];

    EXPECT_TRUE(a1 == t1);
    EXPECT_TRUE(a2 == t2);
}
TEST_F(TestParameters, settingParameters) 
{
    int t1 = 5; double t2 = 15.8;
    p1[1] = t1; p2[1] = t2; 
    EXPECT_TRUE(p1[1]== t1);
    EXPECT_TRUE(p2[1]== t2);
}

TEST_F(TestParametersArithmeticAndAssigningOperator, additionBetweenParameters)
{
    Parameters<2> result = p1 + p2;
    EXPECT_NEAR(result[0], p1_p_p2[0], 0.001);
    EXPECT_NEAR(result[1], p1_p_p2[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, additionWithScalar)
{
    Parameters<2> result = p1 + add;
    EXPECT_NEAR(result[0], p1_a[0], 0.001);
    EXPECT_NEAR(result[1], p1_a[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, compoundAddition)
{
    Parameters<2> result = p2;
    result += p3;
    EXPECT_NEAR(result[0], p2_p_p3[0], 0.001);
    EXPECT_NEAR(result[1], p2_p_p3[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, subtractionBetweenParameters)
{
    Parameters<2> result = p1 - p2;
    EXPECT_NEAR(result[0], p1_m_p2[0], 0.001);
    EXPECT_NEAR(result[1], p1_m_p2[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, subtractionWithScalar)
{
    Parameters<2> result = p1 - sub;
    EXPECT_NEAR(result[0], p1_s[0], 0.001);
    EXPECT_NEAR(result[1], p1_s[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, compoundSubtraction)
{
    Parameters<2> result = p2;
    result -= p3;
    EXPECT_NEAR(result[0], p2_m_p3[0], 0.001);
    EXPECT_NEAR(result[1], p2_m_p3[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, multiplicationWithScalar)
{
    Parameters<2> result = p1 * mull;
    EXPECT_NEAR(result[0], p1_m[0], 0.001);
    EXPECT_NEAR(result[1], p1_m[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, compoundMultiplication)
{
    Parameters<2> result = p2;
    result *= mull;
    EXPECT_NEAR(result[0], p2_m[0], 0.001);
    EXPECT_NEAR(result[1], p2_m[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, divisionWithScalar)
{
    Parameters<2> result = p1 / div;
    EXPECT_NEAR(result[0], p1_d[0], 0.001);
    EXPECT_NEAR(result[1], p1_d[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, compoundDivision)
{
    Parameters<2> result = p2;
    result /= div;
    EXPECT_NEAR(result[0], p2_d[0], 0.001);
    EXPECT_NEAR(result[1], p2_d[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, additionBetweenParameters_p2)
{
    Parameters<2> result = p2 + p3;
    EXPECT_NEAR(result[0], p2_p_p3[0], 0.001);
    EXPECT_NEAR(result[1], p2_p_p3[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, additionWithScalar_p2)
{
    Parameters<2> result = p2 + add;
    EXPECT_NEAR(result[0], p2_a[0], 0.001);
    EXPECT_NEAR(result[1], p2_a[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, compoundAddition_p2)
{
    Parameters<2> result = p3;
    result += p2;
    EXPECT_NEAR(result[0], p2_p_p3[0], 0.001);
    EXPECT_NEAR(result[1], p2_p_p3[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, subtractionBetweenParameters_p2)
{
    Parameters<2> result = p1-p2;
    EXPECT_NEAR(result[0], p1_m_p2[0], 0.001);
    EXPECT_NEAR(result[1], p1_m_p2[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, subtractionWithScalar_p2)
{
    Parameters<2> result = p2 - sub;
    EXPECT_NEAR(result[0], p2_s[0], 0.001);
    EXPECT_NEAR(result[1], p2_s[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, compoundSubtraction_p2)
{
    Parameters<2> result = p2;
    result -= p3;
    EXPECT_NEAR(result[0], p2_m_p3[0], 0.001);
    EXPECT_NEAR(result[1], p2_m_p3[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, multiplicationWithScalar_p2)
{
    Parameters<2> result = p2 * mull;
    EXPECT_NEAR(result[0], p2_m[0], 0.001);
    EXPECT_NEAR(result[1], p2_m[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, compoundMultiplication_p2)
{
    Parameters<2> result = p2;
    result *= mull;
    EXPECT_NEAR(result[0], p2_m[0], 0.001);
    EXPECT_NEAR(result[1], p2_m[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, divisionWithScalar_p2)
{
    Parameters<2> result = p2 / div;
    EXPECT_NEAR(result[0], p2_d[0], 0.001);
    EXPECT_NEAR(result[1], p2_d[1], 0.001);
}
TEST_F(TestParametersArithmeticAndAssigningOperator, compoundDivision_p2)
{
    Parameters<2> result = p2;
    result /= div;
    EXPECT_NEAR(result[0], p2_d[0], 0.001);
    EXPECT_NEAR(result[1], p2_d[1], 0.001);
}
