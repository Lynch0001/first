//
// Created by tlynch on 7/16/22.
//
#include "../src/Validator.h"
#include <gtest/gtest.h>

Validator validator;

TEST(ValidatorTests, TestStructValPass_Min_All)
{
    const Struct_input s = {"1", "1", "0.1", "0.1"};
    const auto expected = true;
    const auto actual = validator.validate(s);
    ASSERT_EQ(expected, actual);
}

TEST(ValidatorTests, TestStructValPass_Max_All)
{
    const Struct_input s = {"150", "150", "40.05", "20.65"};
    const auto expected = true;
    const auto actual = validator.validate(s);
    ASSERT_EQ(expected, actual);
}

TEST(ValidatorTests, TestStructValFail_SIA)
{
    const Struct_input s = {"151", "25", "24.6", "14.0"};
    const auto expected = false;
    const auto actual = validator.validate(s);
    ASSERT_EQ(actual, expected);
}

TEST(ValidatorTests, TestStructValFail_SIB)
{
    const Struct_input s = {"65", "151", "24.6", "14.0"};
    const auto expected = false;
    const auto actual = validator.validate(s);
    ASSERT_EQ(actual, expected);
}

TEST(ValidatorTests, TestStructValFail_SDC)
{
    const Struct_input s = {"65", "25", "41.1", "14.0"};
    const auto expected = false;
    const auto actual = validator.validate(s);
    ASSERT_EQ(actual, expected);
}

TEST(ValidatorTests, TestStructValFail_SDD)
{
    const Struct_input s = {"65", "25", "24.6", "21.75"};
    const auto expected = false;
    const auto actual = validator.validate(s);
    ASSERT_EQ(actual, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}