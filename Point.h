#pragma once

#include <ostream>

class Point {
public:
    double x, y;

    Point() = default;
    Point(double x, double y);
};

std::ostream& operator<<(std::ostream& os, const Point& point);