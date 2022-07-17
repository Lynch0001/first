//
// Created by tlynch on 7/17/22.
//
#include "../src/Validator.h"
#include <gtest/gtest.h>

class ValidatorMultipleParametersTests :public ::testing::TestWithParam<std::tuple<Struct_input, bool>> {

protected:
    Validator validator;
};

TEST_P(ValidatorMultipleParametersTests, checkIfValidTest) {
bool expected = std::get<1>(GetParam());
Struct_input inputStruct = std::get<0>(GetParam());
ASSERT_EQ(expected, validator.validate(inputStruct));
}

INSTANTIATE_TEST_CASE_P(
        ValidatorTests,
        ValidatorMultipleParametersTests,
        ::testing::Values(
        std::make_tuple(Struct_input{"1", "1", "0.1", "0.1"}, true), // valid mins
        std::make_tuple(Struct_input{"0", "1", "0.1", "0.1"}, false), // below min SIA
        std::make_tuple(Struct_input{"1", "0", "0.1", "0.1"}, false), // below min SIB
        std::make_tuple(Struct_input{"1", "1", "0.0", "0.1"}, false), // below min SDC
        std::make_tuple(Struct_input{"1", "1", "0.1", "0.0"}, false), // below min SDD
        std::make_tuple(Struct_input{"-1", "1", "0.1", "0.0"}, false), // below min SIA Neg
        std::make_tuple(Struct_input{"1", "-1", "0.1", "0.0"}, false), // below min SIB Neg
        std::make_tuple(Struct_input{"1", "1", "-0.1", "0.1"}, false), // below min SDC Neg
        std::make_tuple(Struct_input{"1", "1", "0.1", "-0.1"}, false), // below min SDD Neg
        std::make_tuple(Struct_input{"150", "150", "40.05", "20.65"}, true), // valid maxs
        std::make_tuple(Struct_input{"151", "25", "24.6", "14.0"}, false), // above max SIA
        std::make_tuple(Struct_input{"65", "151", "24.6", "14.0"}, false), // above max SIB
        std::make_tuple(Struct_input{"65", "25", "41.1", "14.0"},false),  // above max SDC
        std::make_tuple(Struct_input{"65", "25", "24.6", "21.75"}, false) // above max SDD
        ));