#pragma once

#include <vector>

struct Point {
    double x, y;

    bool operator==(const Point& other);
};

class Polygon {
private:
    std::vector<Point> vertices;
public:
    Polygon();
    Polygon(const std::vector<Point> vertices);
    Polygon(std::initializer_list<Point> points);

    Point& operator[](int index);

    Polygon& operator+=(Point point);
    Polygon& operator-=(Point point);

    bool operator==(const Polygon& other);

    double perimeter();
    double area();

    int vertexCount();
};
