cmake_minimum_required(VERSION 3.22)
project(mapTemplate)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(mapTemplate
        Map.h
        Employee.h
        Employee.cpp
        #TestMap.cpp
        testCustom.cpp
        Book.h)

target_link_libraries(mapTemplate PRIVATE
        GTest::gtest_main
)

gtest_discover_tests(mapTemplate)