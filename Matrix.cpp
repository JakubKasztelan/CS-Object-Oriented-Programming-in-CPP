#include "Matrix.h"
#include "MatrixExceptions.h"

#include <iostream>
#include <fstream>


Matrix::Matrix(int rows, int columns) {
    this->data = new matrixData();

    data->rows = rows;
    data->columns = columns;

    data->arr = new double*[rows];
    for (int i = 0; i < data->rows; i++) {
        data->arr[i] = new double[data->columns];
    }

    data->referenceCounter = 1;
}

Matrix::Matrix(const Matrix& other) {
    this->data = other.data;
    this->data->referenceCounter++;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    if (data->referenceCounter != 0) {
        (data->referenceCounter)--;
        if (data->referenceCounter == 0) {
            for (int i = 0; i < data->rows; i++) {
                delete [] data->arr[i];
            }
            delete [] data->arr;
            delete data;
        }
    }

    this->data = other.data;
    this->data->referenceCounter++;

    return *this;
}

Matrix::~Matrix() {
    (data->referenceCounter)--;
    if (data->referenceCounter != 0) {
        return;
    }

    for (int i = 0; i < data->rows; i++) {
        delete [] data->arr[i];
    }
    delete [] data->arr;

    delete data;
}


void Matrix::loadFromFile(std::string filepath) {
    std::ifstream file(filepath);

    if (!file) {
        throw FileReadException("Error loading the file");
    }

    file >> *this;
}


double Matrix::operator()(int row, int column) const {
    return data->arr[row][column];
}

double &Matrix::operator()(int row, int column) {
    return data->arr[row][column];
}


Matrix& Matrix::operator+=(const Matrix &other) {
    if (data->rows != other.data->rows || data->columns != other.data->columns) {
        throw SizeException("Matrix size mismatch");
    }

    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            data->arr[i][j] += other.data->arr[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator+=(double number) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            data->arr[i][j] += number;
        }
    }

    return *this;
}


Matrix& Matrix::operator-=(const Matrix &other) {
    if (data->rows != other.data->rows || data->columns != other.data->columns) {
        throw SizeException("Matrix size mismatch");
    }

    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            data->arr[i][j] -= other.data->arr[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(double number) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            data->arr[i][j] -= number;
        }
    }

    return *this;
}


Matrix& Matrix::operator*=(const Matrix& other) {
    if (data->columns != other.data->rows) {
        throw SizeException("Matrix size mismatch");
    }

    Matrix temp(data->rows, other.data->columns);

    for (int i = 0; i < temp.data->rows; i++) {
        for (int j = 0; j < temp.data->columns; j++) {
            temp.data->arr[i][j] = 0;
            for (int k = 0; k < data->columns; k++) {
                temp.data->arr[i][j] += data->arr[i][k] * other.data->arr[k][j];
            }
        }
    }

    *this = temp;
    return *this;
}

Matrix& Matrix::operator*=(double number) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            data->arr[i][j] *= number;
        }
    }

    return *this;
}


bool Matrix::operator==(const Matrix& other) const{
    if (this->data->rows != other.data->rows || this->data->columns != other.data->columns) {
        return false;
    }

    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            if (this->data->arr[i][j] != other.data->arr[i][j]) {
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
    return data->referenceCounter;
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

    if (matrix.data->arr) {
        if (--(matrix.data->referenceCounter) == 0) {
            for (int i = 0; i < matrix.data->rows; i++) {
                delete [] matrix.data->arr[i];
            }
            delete [] matrix.data->arr;
            delete matrix.data;
        }
        matrix.data = new matrixData();
        matrix.data->arr = nullptr;
        matrix.data->referenceCounter = 0;
    }

    matrix.data->rows = rows;
    matrix.data->columns = columns;
    matrix.data->arr = new double*[matrix.data->rows];
    for (int i = 0; i < matrix.data->rows; i++) {
        matrix.data->arr[i] = new double[matrix.data->columns];
    }
    matrix.data->referenceCounter = 1;

    for (int i = 0; i < matrix.data->rows; i++) {
        for (int j = 0; j < matrix.data->columns; j++) {
            if (!(is >> matrix.data->arr[i][j])) {
                throw MatrixReadException("Error reading the matrix");
            }
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.data->rows; i++) {
        for (int j = 0; j < matrix.data->columns; j++) {
            os << matrix.data->arr[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
