#include "../hypocycloid.h"
#include "gtest/gtest.h"
TEST(constuct, get)
{
    hypocyc::Point p(4, 5);
    hypocyc::hypocycloid a(p, 10, 4 , 4);
    ASSERT_EQ(10, a.get_R());
    ASSERT_EQ(4, a.get_r());
    ASSERT_EQ(4, a.get_dist());
}
TEST(construct, set)
{
    hypocyc::Point p(4, 5);
    hypocyc::hypocycloid a;
    a.set_r(10);
    a.set_R(4);
    a.set_dist(4);
    ASSERT_EQ(10, a.get_r());
    ASSERT_EQ(4, a.get_R());
    ASSERT_EQ(4, a.get_dist());
}

TEST(methods, coordinates)
{
    double error = 0.001;
    hypocyc::Point p(4, 5);
    hypocyc::hypocycloid b(p, 10, 4 , 4);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.coordinates(34).x, 8.52884, error);
    ASSERT_NEAR(b.coordinates(34).y, 143.834, error);

}

TEST(methods, radius_of_curvature)
{
    double error = 0.001;
    hypocyc::Point p(4, 5);
    hypocyc::hypocycloid b(p, 10, 4 , 4);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.radius_of_curvature(4), 17.4585, error);

}

TEST(methods, sec_square)
{
    double error = 0.001;
    hypocyc::Point p(4, 5);
    hypocyc::hypocycloid b(p, 10, 4 , 4);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.sec_square(89), 11187.5, error);
}

TEST(methods, type1)
{
    double error = 0.001;
    hypocyc::Point p(4, 5);
    hypocyc::hypocycloid b(p, 10, 4 , 4);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.type(), 1, error);
}

TEST(methods, type2)
{
    double error = 0.001;
    hypocyc::Point p(4, 5);
    hypocyc::hypocycloid b(p, 10, 4 , 4);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.type(), 2, error);
}


TEST(methods, type3)
{
    double error = 0.001;
    hypocyc::Point p(4, 5);
    hypocyc::hypocycloid b(p, 10, 4 , 4);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.type(), 3, error);
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}