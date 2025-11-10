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
    if (this == &other) {
        return *this;
    }

    if (referenceCounter != nullptr) {
        (*referenceCounter)--;
        if (*referenceCounter == 0) {
            for (int i = 0; i < rows; i++) {
                delete [] arr[i];
            }
            delete [] arr;
            delete referenceCounter;
        }
    }

    arr = other.arr;
    rows = other.rows;
    columns = other.columns;
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

Matrix& Matrix::operator+=(double number) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] += number;
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

Matrix& Matrix::operator-=(double number) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] -= number;
        }
    }

    return *this;
}


Matrix& Matrix::operator*=(const Matrix& other) {
    if (columns != other.rows) {
        std::cout << "Size mismatch\n";
        return *this;
    }

    Matrix temp(rows, other.columns);

    for (int i = 0; i < temp.rows; i++) {
        for (int j = 0; j < temp.columns; j++) {
            temp.arr[i][j] = 0;
            for (int k = 0; k < columns; k++) {
                temp.arr[i][j] += arr[i][k] * other.arr[k][j];
            }
        }
    }

    *this = temp;
    return *this;
}

Matrix& Matrix::operator*=(double number) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] *= number;
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
    return !(*this == other);
}


Matrix operator+(const Matrix& a, const Matrix& b) {
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

Matrix operator+(const Matrix& a, double number) {
    Matrix c(a.rows, a.columns);

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.columns; j++) {
            c.arr[i][j] = a.arr[i][j] + number;
        }
    }

    return c;
}

Matrix operator+(double number, const Matrix& a) {
    Matrix c(a.rows, a.columns);

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.columns; j++) {
            c.arr[i][j] = a.arr[i][j] + number;
        }
    }

    return c;
}


Matrix operator-(const Matrix& a, const Matrix& b) {
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

Matrix operator-(const Matrix& a, double number) {
    Matrix c(a.rows, a.columns);

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.columns; j++) {
            c.arr[i][j] = a.arr[i][j] - number;
        }
    }

    return c;
}

Matrix operator-(double number, const Matrix& a) {
    Matrix c(a.rows, a.columns);

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.columns; j++) {
            c.arr[i][j] = a.arr[i][j] - number;
        }
    }

    return c;
}


Matrix operator*(const Matrix& a, const Matrix& b) {
    if (a.columns != b.rows) {
        std::cout << "Size mismatch\n";
        return Matrix(0, 0);
    }

    Matrix c(a.rows, b.columns);

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.columns; j++) {
            c.arr[i][j] = 0;
            for (int k = 0; k < a.columns; k++) {
                c.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            }
        }
    }

    return c;
}

Matrix operator*(const Matrix& a, double number) {
    Matrix c(a.rows, a.columns);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.columns; j++) {
            c.arr[i][j] = a.arr[i][j] * number;
        }
    }

    return c;
}

Matrix operator*(double number, const Matrix& a) {
    Matrix c(a.rows, a.columns);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.columns; j++) {
            c.arr[i][j] = a.arr[i][j] * number;
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
