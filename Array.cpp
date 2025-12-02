#include "Array.h"

Array::Array() {
    data = nullptr;
    size = 0;
}

Array::Array(int numOfElements) {
    data = new double[numOfElements];
    size = numOfElements;
}

void Array::fill(double value) {
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
}

void Array::add(double value) {
    size++;
    double* newData = new double[size];
    for (int i = 0; i < size - 1; i++) {
        newData[i] = data[i];
    }
    newData[size - 1] = value;
    delete [] data;
    data = newData;
}

void Array::setElement(int index, double value) {
    data[index] = value;
}

void Array::swap(Array& other) {
    std::swap(this->data, other.data);
    std::swap(this->size, other.size);
}

void Array::append(const Array& other) {
    for (int i = 0; i < other.size; i++) {
        this->add(other.data[i]);
    }
}

int Array::getSize() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const Array& array) {
    os << "[";
    for (int i = 0; i < array.size; i++) {
        os << array.data[i];
        if (i < array.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
