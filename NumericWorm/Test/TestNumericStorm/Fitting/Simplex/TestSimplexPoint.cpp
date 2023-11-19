
#include "pch.h"

using namespace NumericStorm::Fitting;
struct TestData 
{
	std::array<double, 2> a1{ 1.0,2.0 };
	std::array<int, 2> a2{ 1,5 };

	Parameters<double, 2> p1{ a1 };
	Parameters<int, 2> p2{a2};
	double t1 = 1.0;
	int t2 = 5;
};

struct CreatingSimpelxPoint:public testing::Test
{
	TestData testdata;
};
struct OperatorSimplexPoint :public testing::Test
{
	TestData testdata;
	SimplexPoint<double, 2> d1{ testdata.p1 };
	SimplexPoint<int, 2> d2{ testdata.p2 };


};


TEST_F(CreatingSimpelxPoint, creatingByList) 
{
	SimplexPoint<double, 2> d1(1.0, 2.0);
	SimplexPoint<int, 2> d2(1, 2);
	double t1 = 1.0, e1 = d1.getParameters()[0];
	int t2 = 1, e2 = d2.getParameters()[0];
	EXPECT_EQ(e1, t1);
	EXPECT_EQ(e2, t2);
}

TEST_F(CreatingSimpelxPoint, creatingByCreatedArray)
{
	SimplexPoint<double, 2> d1{testdata.p1};
	SimplexPoint<int, 2> d2{testdata.p2};
	double e1 = d1.getParameters()[0];
	int e2 = d2.getParameters()[0];
	EXPECT_EQ(e1, testdata.p1[0]);
	EXPECT_EQ(e2, testdata.p2[0]);
}

TEST_F(OperatorSimplexPoint, operatorEqual)
{

	EXPECT_EQ(d1,testdata.p1);
	EXPECT_EQ(d2,testdata.p2);
}

TEST_F(OperatorSimplexPoint, testingGettingAccesOperator)
{
	EXPECT_EQ(d1[0], testdata.t1 );
	EXPECT_EQ(d2[1], testdata.t2);

	EXPECT_NE(d2[1], testdata.t1);

	EXPECT_EQ(d1[10], testdata.t1);
	EXPECT_EQ(d1[-1], testdata.t1);
	
}

TEST_F(OperatorSimplexPoint, settingAccesOperator) 
{
	testdata.t1 = 10.0;  testdata.t2 = 5;
	d1[1] = testdata.t1;
	d2[1] = testdata.t2;
	EXPECT_EQ(d1[1],testdata.t1);
	EXPECT_EQ(d2[1],testdata.t2);

	d1[-1] = testdata.t1;
	d2[10] = testdata.t2;
	EXPECT_EQ(d1[0], testdata.t1);
	EXPECT_EQ(d2[0], testdata.t2);
}