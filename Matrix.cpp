#include "Matrix.h"

#include <iostream>
#include <fstream>

Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    referenceCounter = new int(1);

    arr = new double*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[columns];
    }
}

Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    columns = other.columns;

    arr = other.arr;
    referenceCounter = other.referenceCounter;
    (*referenceCounter)++;
}

Matrix& Matrix::operator=(const Matrix& other) {
    rows = other.rows;
    columns = other.columns;

    if (this->arr != nullptr) {
        for (int i = 0; i < rows; i++) {
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

    for (int i = 0; i < rows; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    delete referenceCounter;
}


void Matrix::loadFromFile(std::string filepath) {
    std::ifstream file(filepath);

    // Add exception here

    file >> *this;
}


Matrix& Matrix::operator+=(const Matrix &other) {
    if (rows != other.rows || columns != other.columns) {
        std::cout << "Size mismatch\n";
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] += other.arr[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix &other) {
    if (rows != other.rows || columns != other.columns) {
        std::cout << "Size mismatch\n";
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] -= other.arr[i][j];
        }
    }

    return *this;
}


bool Matrix::operator==(const Matrix& other) const{
    if (this->rows != other.rows || this->columns != other.columns) {
        return false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (this->arr[i][j] != other.arr[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other) const{
    if (this->rows != other.rows || this->columns != other.columns) {
        return false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (this->arr[i][j] == other.arr[i][j]) {
                return false;
            }
        }
    }

    return true;
}


Matrix operator+(const Matrix &a, const Matrix &b) {
    if (a.rows != b.rows || a.columns != b.columns) {
        std::cout << "Size mismatch\n";
    }

    Matrix c(a.rows, a.columns);

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.columns; j++) {
            c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }

    return c;
}

Matrix operator-(const Matrix &a, const Matrix &b) {
    if (a.rows != b.rows || a.columns != b.columns) {
        std::cout << "Size mismatch\n";
    }

    Matrix c(a.rows, a.columns);

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.columns; j++) {
            c.arr[i][j] = a.arr[i][j] - b.arr[i][j];
        }
    }

    return c;
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
            for (int i = 0; i < matrix.rows; i++) {
                delete [] matrix.arr[i];
            }
            delete [] matrix.arr;
            delete matrix.referenceCounter;
        }
        matrix.arr = nullptr;
        matrix.referenceCounter = nullptr;
    }

    matrix.rows = rows;
    matrix.columns = columns;
    matrix.arr = new double*[matrix.rows];
    for (int i = 0; i < matrix.rows; i++) {
        matrix.arr[i] = new double[matrix.columns];
    }
    matrix.referenceCounter = new int(1);

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            if (!(is >> matrix.arr[i][j])) {
                std::cout << "Read error\n";
            }
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            os << matrix.arr[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
