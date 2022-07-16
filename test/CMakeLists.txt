cmake_minimum_required(VERSION 3.22)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
add_executable(validator_test validator_test.cpp validator_test.cpp)

target_link_libraries(validator_test
        PRIVATE
        GTest::GTest
        first)

add_test(validator_gtests validator_test)
