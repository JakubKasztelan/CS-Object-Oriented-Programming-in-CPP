#ifndef MARTIX_H
#define MARTIX_H

#include <ostream>
#include <istream>

class Matrix {
public:
    double **arr;
    int capacityRow;
    int capacityCol;
    int sizeRow;
    int sizeCol;
    int *referenceCounter;

    Matrix();
    Matrix(Matrix& other);
    Matrix& operator=(Matrix& other);
    ~Matrix();

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

#endif //MARTIX_H