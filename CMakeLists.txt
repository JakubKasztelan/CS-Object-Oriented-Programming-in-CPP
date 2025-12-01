cmake_minimum_required(VERSION 3.22)
project(Test)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(Polygon main.cpp
        Polygon.h
        Polygon.cpp
        PolygonExceptions.h
        Polygon.h
        main.cpp
        PolygonExceptions.cpp)

target_link_libraries(Polygon PRIVATE
        GTest::gtest_main
)

gtest_discover_tests(Polygon)