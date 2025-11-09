#ifndef MARTIX_H
#define MARTIX_H

#include <ostream>

class Matrix {
private:
    double *arr;

public:
    Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
};

Matrix operator+(const Matrix& a, const Matrix& b);
Matrix operator-(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, const Matrix& b);

std::ostream& operator<<(std::ostream& os, const Matrix& other);

#endif //MARTIX_H