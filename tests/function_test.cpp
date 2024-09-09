#include <gtest/gtest.h>
#include <function.h>

TEST(test, 1)
{
    unsigned int devider = 2;
    unsigned int bound = 5;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 4);
}

TEST(test, 2)
{
    unsigned int devider = 3;
    unsigned int bound = 9;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 9);
}

TEST(test, 3)
{
    unsigned int devider = 2;
    unsigned int bound = 19;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 18);
}

TEST(test, 4)
{
    unsigned int devider = 1;
    unsigned int bound = 190;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 190);
}

TEST(test, 5)
{
    unsigned int devider = 20;
    unsigned int bound = 20;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 20);
}

TEST(test, 6)
{
    unsigned int devider = 2000;
    unsigned int bound = 6000;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 6000);
}

TEST(test, 7)
{
    unsigned int devider = 45;
    unsigned int bound = 90;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 90);
}

TEST(test, 8)
{
    unsigned int devider = 1000;
    unsigned int bound = 1001;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 1000);
}

TEST(test, 9)
{
    unsigned int devider = 3;
    unsigned int bound = 190;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 189);
}

TEST(test, 10)
{
    unsigned int devider = 5;
    unsigned int bound = 2;

    EXPECT_THROW(findMaxDividend(devider, bound), std::runtime_error);
}
