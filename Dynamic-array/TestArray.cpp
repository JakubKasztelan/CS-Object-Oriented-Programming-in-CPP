#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    cout << "Functionality for 60%" << endl;

    Array a1(2);
    a1.fill(1.6);

    cout << a1 << endl;
    cout << a1.getSize() << endl;

    a1.add(7.9);

    cout << a1 << endl;
    cout << a1.getSize() << endl;

    a1.setElement(0, 0.3);
    a1.setElement(2, 3.4);

    cout << a1 << endl;

    Array a2(4);
    a2.fill(0.8);
    a2.setElement(2, -0.3);

    cout << a2 << endl;
    cout << a2.getSize() << endl;

    cout << "Functionality for 80%" << endl;

    a1.swap(a2);

    cout << a1 << endl;
    cout << a1.getSize() << endl;

    cout << a2 << endl;
    cout << a2.getSize() << endl;

    cout << "Functionality for 100%" << endl;

    Array a3 = a1;
    a3.append(a2);
    cout << a3 << endl;

    return 0;
}
