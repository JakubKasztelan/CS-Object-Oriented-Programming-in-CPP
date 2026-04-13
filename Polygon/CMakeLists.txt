cmake_minimum_required(VERSION 3.26)
project(Polygon)

set(CMAKE_CXX_STANDARD 20)

add_executable(polygon
        Point.cpp
        Point.h
        Polygon.cpp
        Polygon.h
        PolygonExceptions.cpp
        PolygonExceptions.h
        TestPolygon.cpp
)