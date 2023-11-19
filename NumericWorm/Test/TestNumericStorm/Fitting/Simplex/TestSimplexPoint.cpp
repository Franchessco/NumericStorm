
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

//template<typename T_d>
//typedef std::vector<T_d>(*model)(std::array<double, 2> param,std::vector<T_d>arguments);


struct CreatingSimpelxPoint:public testing::Test
{
	TestData testdata;
};
struct OperatorSimplexPoint :public testing::Test
{
	
	TestData testdata;
	SimplexPoint<double, 2,double> d1{ testdata.p1 };
	SimplexPoint<int, 2,double> d2{ testdata.p2 };


};

TEST_F(CreatingSimpelxPoint, creatingByList) 
{
	SimplexPoint<double, 2,double> d1(1.0, 2.0);
	SimplexPoint<int, 2,double> d2(1, 2);
	double t1 = 1.0, e1 = d1.getParameters()[0];
	int t2 = 1, e2 = d2.getParameters()[0];
	EXPECT_EQ(e1, t1);
	EXPECT_EQ(e2, t2);
}

TEST_F(CreatingSimpelxPoint, creatingByCreatedArray)
{
	SimplexPoint<double, 2,double> d1{testdata.p1};
	SimplexPoint<int, 2,double> d2{testdata.p2};
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

struct BoundsSetting : public testing::Test
{
	Bounds<double, 4> minBounds{1,2,3,4};
	Bounds<double, 4> maxBounds{ 11,12,13,14};

	SimplexPoint<double, 4,double> P_onlymin{ 0.1,0.2,0.3,0.4 };
	SimplexPoint<double, 4,double> P_onlymax{ 21,22,23,24 };
	SimplexPoint<double, 4,double> P_mix{ 21,0.1,28,0.5 };


};

TEST_F(BoundsSetting, TestBoundsSetting) 
{
	P_onlymin.setToBounds(minBounds, maxBounds);
	EXPECT_TRUE(P_onlymin == minBounds);

	P_onlymax.setToBounds(minBounds, maxBounds);
	EXPECT_TRUE(P_onlymax == maxBounds);


};

std::vector<double> modelOfLine(Parameters<double, 2> arguments, std::vector<double>& x) {
	
	for (size_t i = 0; i < x.size(); ++i) 
		x[i] *= arguments[0]+arguments[1];
	return x;
}
using model = std::vector<double>(*)(Parameters<double, 2> param, std::vector<double>& args);

struct ModelAndError : public testing::Test {
	SimplexPoint<double, 2,double> linearModel{ 1.0, 2.0 };
	model linmodel = modelOfLine;
	// Call setModel in a member function or constructor
	
};
TEST_F(ModelAndError,testingSettingModelAndError) 
{
	linearModel.setModel(linmodel);

};