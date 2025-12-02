#ifndef ARRAY_H
#define ARRAY_H

#include <ostream>

class Array {
public:
    Array();

    Array(int numOfElements);

    Array(const Array& other);

    Array& operator=(const Array& other);

    ~Array();

    void fill(double value);

    void add(double value);

    void setElement(int index, double value);

    void swap(Array& other);

    void append(const Array& other);

    int getSize() const;

    friend std::ostream& operator<<(std::ostream& os, const Array& array);

private:
    double* data;
    int size;
};


#endif //ARRAY_H
