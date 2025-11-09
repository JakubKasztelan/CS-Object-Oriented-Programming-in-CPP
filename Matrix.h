#ifndef MARTIX_H
#define MARTIX_H

#include <ostream>

class Matrix {
public:
    Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    operator==(const Matrix& other) const;
    operator!=(const Matrix& other) const;
};

Matrix operator+(const Matrix& a, const Matrix& b);
Matrix operator-(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, const Matrix& b);

std::ostream& operator<<(std::ostream& os, const Matrix& other);

#endif //MARTIX_H