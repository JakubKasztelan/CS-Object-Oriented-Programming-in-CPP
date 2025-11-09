#ifndef MARTIX_H
#define MARTIX_H

#include <ostream>

class Martix {
public:
    Martix();
    Martix(const Martix& other);
    Martix& operator=(const Matrix& other);

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
//comment

#endif //MARTIX_H
