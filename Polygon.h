#pragma once

#include "Point.h"
#include <vector>

class Polygon {
public:
    Polygon();

    void add(const Point& point);

    Polygon operator*(double scale) const;
    Polygon& operator+=(const Point &vector);

    Point& operator[](int index);

    friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon);

private:
    std::vector<Point> vertices;
};

Polygon operator*(const double& scale, const Polygon& polygon);
