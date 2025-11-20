#include "Matrix.h"
#include "MatrixExceptions.h"

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

    if (!file) {
        throw FileReadException("Error loading the file");
    }

    file >> *this;
}


double Matrix::operator()(int row, int column) const {
    return arr[row][column];
}

double &Matrix::operator()(int row, int column) {
    return arr[row][column];
}


Matrix& Matrix::operator+=(const Matrix &other) {
    if (rows != other.rows || columns != other.columns) {
        throw SizeException("Matrix size mismatch");
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
        throw SizeException("Matrix size mismatch");
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
        throw SizeException("Matrix size mismatch");
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

int Matrix::getReferenceCounter() const{
    return *referenceCounter;
}

Matrix operator+(const Matrix& a, const Matrix& b) {
    Matrix c = a;
    c += b;
    return c;
}

Matrix operator+(const Matrix& a, double number) {
    Matrix c = a;
    c += number;
    return c;
}

Matrix operator+(double number, const Matrix& a) {
    Matrix c = a;
   c += number;
    return c;
}


Matrix operator-(const Matrix& a, const Matrix& b) {
    Matrix c = a;
    c -= b;
    return c;
}

Matrix operator-(const Matrix& a, double number) {
    Matrix c = a;
    c -= number;
    return c;
}

Matrix operator-(double number, const Matrix& a) {
    Matrix c = a;
    c -= number;
    return c;
}


Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix c = a;
    c *= b;
    return c;
}

Matrix operator*(const Matrix& a, double number) {
    Matrix c = a;
    c *= number;
    return c;
}

Matrix operator*(double number, const Matrix& a) {
    Matrix c = a;
    c *= number;
    return c;
}


std::istream& operator>>(std::istream& is, Matrix& matrix) {
    int rows, columns;

    if (!(is >> rows >> columns)) {
        throw MatrixReadException("Failed to load matrix dimensions");
    }

    if (rows <= 0 || columns <= 0) {
        throw SizeException("Invalid matrix dimensions");
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
                throw MatrixReadException("Error reading the matrix");
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
