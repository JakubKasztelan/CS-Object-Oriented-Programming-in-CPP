#include "Polygon.h"
#include "PolygonExceptions.h"

Polygon::Polygon() {
}

void Polygon::add(const Point& point) {
    vertices.push_back(point);
}

Polygon Polygon::operator*(double scale) const {
    Polygon newPolygon;
    for (Point point: vertices) {
        point.x *= scale;
        point.y *= scale;
        newPolygon.add(point);
    }
    return newPolygon;
}

Polygon& Polygon::operator+=(const Point& vector) {
    for (Point& point: vertices) {
        point.x += vector.x;
        point.y += vector.y;
    }
    return *this;
}

Point& Polygon::operator[](int index) {
    if (index < 0 || index >= vertices.size()) {
        throw IndexOutOfBoundsException("Index out of bounds");
    }
    return vertices.at(index);
}

std::ostream& operator<<(std::ostream& os, const Polygon& polygon) {
    for (int i = 0; i < polygon.vertices.size(); i++) {
        os << "point " << i << ": " << polygon.vertices.at(i);
        if (i < polygon.vertices.size() - 1) {
            os << std::endl;
        }
    }
    return os;
}

Polygon operator*(const double& scale, const Polygon& polygon) {
    return polygon * scale;
}
