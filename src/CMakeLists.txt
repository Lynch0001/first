cmake_minimum_required(VERSION 3.22)

add_library(first main.cpp)

target_include_directories(first PUBLIC include)
