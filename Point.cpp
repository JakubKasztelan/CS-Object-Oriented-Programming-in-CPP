#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
