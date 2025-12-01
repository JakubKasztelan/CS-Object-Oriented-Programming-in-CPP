#include <iostream>
#include "Polygon.h"
#include "PolygonExceptions.h"

using namespace std;

int main() {
    cout << "\nFunctionality for 40%" << endl;

    Point point1;
    point1.x = 1.5;
    point1.y = 2;

    cout << "point1: " << point1 << endl;
    // Prints: "point1: (1.5, 2)"

    Point point2(5.5, 2);

    cout << "point2: " << point2 << endl;
    // Prints: "point2: (5.5, 2)"

    Polygon polygon1;
    polygon1.add(point1);
    polygon1.add(point2);

    cout << "polygon1: " << endl << polygon1 << endl;
    // Prints:
    // "polygon1:"
    // "point 0: (1.5, 2)"
    // "point 1: (5.5, 2)"

    polygon1.add(Point(1.5, 4.3));

    cout << "polygon1: " << endl << polygon1 << endl;
    // Prints:
    // "polygon1:"
    // "point 0: (1.5, 2)"
    // "point 1: (5.5, 2)"
    // "point 2: (1.5, 4.3)"

    cout << "\nFunctionality for 60%" << endl;

    double scale = 0.5;

    Polygon polygon2;
    polygon2 = polygon1 * scale;

    cout << "polygon2: " << endl << polygon2 << endl;
    // Prints:
    // "polygon2:"
    // "point 0: (0.75, 1)"
    // "point 1: (2.75, 1)"
    // "point 2: (0.75, 2.15)"

    scale = 4;
    polygon2 = scale * polygon2;

    cout << "polygon2: " << endl << polygon2 << endl;
    // Prints:
    // "polygon2:"
    // "point 0: (3, 4)"
    // "point 1: (11, 4)"
    // "point 2: (3, 8.6)"

    cout << "\nFunctionality for 80%" << endl;

    Point vector(-0.5, 1);

    Polygon polygon3 = polygon1;
    polygon3 += vector;

    cout << "polygon3: " << endl << polygon3 << endl;
    // Prints:
    // "polygon3:"
    // "point 0: (1, 3)"
    // "point 1: (5, 3)"
    // "point 2: (1, 5.3)"

    (polygon3 += vector) += vector;

    cout << "polygon3: " << endl << polygon3 << endl;
    // Prints:
    // "polygon3:"
    // "point 0: (0, 5)"
    // "point 1: (4, 5)"
    // "point 2: (0, 7.3)"

    cout << "\nFunctionality for 100%" << endl;
    polygon3[0] = Point(0.3, 2.5);
    polygon3[1].x = 0.7;

    cout << "polygon3: " << endl << polygon3 << endl;
    // Prints:
    // "polygon3:"
    // "point 0: (0.3, 2.5)"
    // "point 1: (0.7, 5)"
    // "point 2: (0, 7.3)"

    // The following line throws IndexOutOfBoundsException
    try {
        polygon3[4] = Point(1, 2);
    } catch (IndexOutOfBoundsException e) {
        std::cerr << "Error: " << e.what() << endl;
    }
}
