#include "Polygon.h"
#include "PolygonExceptions.h"

bool Point::operator==(const Point& other) {
    if (this->x == other.x && this->y == other.y) {
        return true;
    }
    return false;
}


Polygon::Polygon() {
}

Polygon::Polygon(const std::vector<Point>& vertices) : vertices(vertices) {
}

Polygon::Polygon(std::initializer_list<Point> points) : vertices(points) {
}


Point& Polygon::operator[](int index) {
    return vertices.at(index);
}


Polygon& Polygon::operator+=(Point point) {
    if (vertices.empty()) {
        throw PolygonEmptyException("The polygon doesn't have vertices");
    }

    for (Point& vertex : vertices) {
        vertex.x += point.x;
        vertex.y += point.y;
    }

    return *this;
}

Polygon& Polygon::operator-=(Point point) {
    if (vertices.empty()) {
        throw PolygonEmptyException("Polygon is empty");
    }

    for (Point& vertex : vertices) {
        vertex.x -= point.x;
        vertex.y -= point.y;
    }

    return *this;
}


bool Polygon::operator==(const Polygon& other) {
    if (this->vertices.empty() || other.vertices.empty()) {
        throw PolygonEmptyException("Polygon is empty");
    }

    if (this->vertices.size() != other.vertices.size()) {
        return false;
    }

    for (int i = 0; i < this->vertices.size(); i++) {
        if (this->vertices.at(i) != other.vertices.at(i)) {
            return false;
        }
    }

    return true;
}


double Polygon::perimeter() {
    if (vertices.empty()) {
        throw PolygonEmptyException("Polygon is empty");
    }

    double perimeter = 0.0;
    int vertexCount = vertices.size();

    for (int i = 0; i < vertexCount; i++) {
        double dx = (double)vertices.at(i).x - vertices.at((i + 1) % vertexCount).x;
        double dy = (double)vertices.at(i).y - vertices.at((i + 1) % vertexCount).y;
        perimeter += sqrt(dx * dx + dy * dy);
    }

    return perimeter;
}

double Polygon::area() {
    if (vertices.empty()) {
        throw PolygonEmptyException("Polygon is empty");
    }

    double sum = 0.0;
    int vertexCount = vertices.size();

    for (int i = 0; i < vertexCount; i++) {
        int j = (i + 1) % vertexCount;
        sum += (double)vertices.at(i).x * vertices.at(j).y;
        sum -= (double)vertices.at(i).y * vertices.at(j).x;
    }

    return std::abs(sum / 2.0);
}


int Polygon::vertexCount() {
    return vertices.size();
}
