#include "pch.h"
#include "pch.h"


using namespace NumericStorm::Fitting;

struct TestBounds :public testing::Test
{
public:

    // Test data

    Bounds<2,int> p1{ 1, 2 };
    Bounds<2> p2{ 1.0, 2.2 };
    

    std::array<int, 2> d1{ 1, 2 };
    std::array<double, 2> d2{ 1.0, 2.2 };
    
};



TEST_F(TestBounds, constructingBoundsbylist)
{
    auto a = p1.getParameters();
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);

    std::array<int, 2> a1{ 1,2 };
    std::array<int, 2> a2{ 1,3 };
    bool b1 = (a == a1), b2 = (a == a2);

    EXPECT_EQ(b1, 1);
    EXPECT_EQ(b2, 0);

}
TEST_F(TestBounds, constructingBoundsbyarray)
{
    Bounds<2,int> p4{ d1 };
    Bounds<2> p5{ d2 };
    
    bool b1 = (p4.getParameters() == d1), b2 = (p5.getParameters() == d2);

    EXPECT_EQ(b1, 1);
    EXPECT_EQ(b2, 1);
}
TEST_F(TestBounds, operatorequal)
{
    EXPECT_EQ(p1, d1);
    EXPECT_EQ(p2, d2);
}
TEST_F(TestBounds, gettingBounds)
{
    int a1; double a2; 

    a1 = p1[1]; a2 = p2[1]; 
    int t1 = d1[1]; double t2 = d2[1];

    EXPECT_EQ(a1, t1);
    EXPECT_EQ(a2, t2);

}

TEST_F(TestBounds, settingBounds)
{
    int t1 = 5; double t2 = 15.8; 

    p1[1] = t1; p2[1] = t2; 
    EXPECT_EQ(p1[1], t1);
    EXPECT_EQ(p2[1], t2);
}