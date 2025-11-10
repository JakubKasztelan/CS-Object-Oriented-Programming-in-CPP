#include "Matrix.h"

#include <iostream>

#define INITIAL_ROWS 10
#define INITIAL_COLUMNS 10

Matrix::Matrix() {
    capacityRow = INITIAL_ROWS;
    capacityCol = INITIAL_COLUMNS;
    sizeRow = 0;
    sizeCol = 0;
    referenceCounter = new int(1);

    arr = new double*[capacityRow];
    for (int i = 0; i < capacityRow; i++) {
        arr[i] = new double[capacityCol];
    }
}

Matrix::Matrix(Matrix& other) {
    capacityRow = other.sizeRow;
    capacityCol = other.sizeCol;
    sizeRow = other.sizeRow;
    sizeCol = other.sizeCol;

    arr = other.arr;
    referenceCounter = other.referenceCounter;
    (*referenceCounter)++;
}

Matrix& Matrix::operator=(Matrix& other) {
    capacityRow = other.sizeRow;
    capacityCol = other.sizeCol;
    sizeRow = other.sizeRow;
    sizeCol = other.sizeCol;

    if (this->arr != nullptr) {
        for (int i = 0; i < sizeRow; i++) {
            delete [] arr[i];
        }
        delete [] arr;
    }

    if (this->referenceCounter != nullptr) {
        referenceCounter--;
    }

    arr = other.arr;
    referenceCounter = other.referenceCounter;
    (*referenceCounter)++;

    return *this;
}

Matrix::~Matrix() {
    (*referenceCounter)--;
    if (*referenceCounter != 0) {
        return;
    }

    for (int i = 0; i < sizeRow; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    delete referenceCounter;
}


bool Matrix::operator==(const Matrix& other) const{
    if (this->sizeRow != other.sizeRow || this->sizeCol != other.sizeCol) {
        return false;
    }

    for (int i = 0; i < sizeRow; i++) {
        for (int j = 0; j < sizeCol; j++) {
            if (this->arr[i][j] != other.arr[i][j]) {
                return false;
            }
        }
    }

    return true;
}


std::istream& operator>>(std::istream& is, Matrix& matrix) {
    int rows, columns;

    if (!(is >> rows >> columns)) {
        std::cout << "Failed to load matrix dimensions\n";
    }

    if (rows <= 0 || columns <= 0) {
        std::cout << "Invalid matrix dimensions\n";
    }

    if (matrix.arr) {
        if (--(*matrix.referenceCounter) == 0) {
            for (int i = 0; i < matrix.capacityRow; i++) {
                delete [] matrix.arr[i];
            }
            delete [] matrix.arr;
            delete matrix.referenceCounter;
        }
        matrix.arr = nullptr;
        matrix.referenceCounter = nullptr;
    }

    matrix.capacityRow = rows;
    matrix.sizeRow = rows;
    matrix.capacityCol = columns;
    matrix.sizeCol = columns;
    matrix.arr = new double*[matrix.sizeRow];
    for (int i = 0; i < matrix.sizeRow; i++) {
        matrix.arr[i] = new double[matrix.sizeCol];
    }
    matrix.referenceCounter = new int(1);

    for (int i = 0; i < matrix.sizeRow; i++) {
        for (int j = 0; j < matrix.sizeCol; j++) {
            if (!(is >> matrix.arr[i][j])) {
                std::cout << "Invalid or incomplete matrix data\n";
            }
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.sizeRow; i++) {
        for (int j = 0; j < matrix.sizeCol; j++) {
            os << matrix.arr[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}