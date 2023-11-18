
#include "pch.h"

using namespace NumericStorm::Fitting;

struct CreatingSimpelxPoint:public testing::Test
{
	std::array<double, 2> a1{ 1.0,2.0 };
	std::array<int, 2> a2{ 1,5 };

	Parameters<double, 2> p1{ a1 };
	Parameters<int, 2> p2{a2};

};
struct OperatorSimplexPoint :public testing::Test, CreatingSimpelxPoint
{
	SimplexPoint<double, 2> d1{ p1 };
	SimplexPoint<int, 2> d2{ p2 };
	double t1 = 1.0;
	int t2 = 1;

};
TEST_F(CreatingSimpelxPoint, creatingByList) 
{
	SimplexPoint<double, 2> d1(1.0, 2.0);
	SimplexPoint<int, 2> d2(1, 2);
	double t1 = 1.0, e1 = d1.getParamters()[0];
	int t2 = 1, e2 = d2.getParamters()[0];
	EXPECT_EQ(e1, t1);
	EXPECT_EQ(e2, t2);
}

TEST_F(CreatingSimpelxPoint, creatingByCreatedArray)
{
	SimplexPoint<double, 2> d1{p1};
	SimplexPoint<int, 2> d2{p2};
	double t1 = 1.0, e1 = d1.getParamters()[0];
	int t2 = 1, e2 = d2.getParamters()[0];
	EXPECT_EQ(e1, t1);
	EXPECT_EQ(e2, t2);
}

TEST_F(OperatorSimplexPoint, testingGettngAccesOperator)
{
	EXPECT_EQ(d1[0],t1 );
	EXPECT_EQ(d2[0], t2);

	EXPECT_NE(d2[1], t1);

	EXPECT_EQ(d1[10], t1);
	EXPECT_EQ(d1[-1], t1);
	
}

TEST_F(OperatorSimplexPoint, settingAccesOperator) 
{

}