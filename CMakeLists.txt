cmake_minimum_required(VERSION 3.29)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(Matrix
        Matrix.cpp
        TestMatrix.cpp)

target_link_libraries(Matrix PRIVATE
        GTest::gtest_main
)

gtest_discover_tests(Matrix)
