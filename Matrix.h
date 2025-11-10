#ifndef MARTIX_H
#define MARTIX_H

#include <ostream>
#include <istream>

class Matrix {
public:
    double **arr;
    int rows;
    int columns;
    mutable int *referenceCounter;

    Matrix(int rows = 0, int columns = 0);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    void loadFromFile(std::string filepath);

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
};

Matrix operator+(const Matrix& a, const Matrix& b);
Matrix operator-(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, const Matrix& b);

std::istream& operator>>(std::istream& is, Matrix& matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& other);

#endif