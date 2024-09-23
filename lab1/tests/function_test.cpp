#include <gtest/gtest.h>
#include <function.h>

TEST(test, deviderHigherBound)
{
    unsigned int devider = 2;
    unsigned int bound = 5;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 4);
}

TEST(test, deviderEqualBound)
{
    unsigned int devider = 3;
    unsigned int bound = 9;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 9);
}

TEST(test, deviderHigherBound1)
{
    unsigned int devider = 2;
    unsigned int bound = 19;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 18);
}

TEST(test, deviderEqualBound1)
{
    unsigned int devider = 1;
    unsigned int bound = 190;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 190);
}

TEST(test, deviderEqualBound2)
{
    unsigned int devider = 20;
    unsigned int bound = 20;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 20);
}

TEST(test, deviderEqualBound3)
{
    unsigned int devider = 2000;
    unsigned int bound = 6000;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 6000);
}

TEST(test, deviderEqualBound4)
{
    unsigned int devider = 45;
    unsigned int bound = 90;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 90);
}

TEST(test, deviderHigherBound2)
{
    unsigned int devider = 1000;
    unsigned int bound = 1001;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 1000);
}

TEST(test, deviderHigherBound3)
{
    unsigned int devider = 3;
    unsigned int bound = 190;

    unsigned int result = findMaxDividend(devider, bound);

    EXPECT_EQ(result, 189);
}

TEST(test, throwErrorCheck)
{
    unsigned int devider = 5;
    unsigned int bound = 2;

    EXPECT_THROW(findMaxDividend(devider, bound), std::runtime_error);
}
