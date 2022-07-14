cmake_minimum_required(VERSION 3.22)
project(first)

set(CMAKE_CXX_STANDARD 20)

add_executable(first main.cpp Validator.h validationresults.h Struct_input.h validationcontext.h validationutil.h siavalidator.h)
