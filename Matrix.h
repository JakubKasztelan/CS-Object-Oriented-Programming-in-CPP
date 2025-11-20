#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <istream>


typedef struct {
    double **arr;
    int rows;
    int columns;
    int referenceCounter;
} matrixData;


class Matrix {
private:
    matrixData *data;

public:
    Matrix(int rows = 0, int columns = 0);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    void loadFromFile(std::string filepath);

    double operator()(int row, int column) const;
    double& operator()(int row, int column);

    Matrix& operator+=(const Matrix& other);
    Matrix& operator+=(double number);

    Matrix& operator-=(const Matrix& other);
    Matrix& operator-=(double number);

    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(double number);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    int getReferenceCounter() const;

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& other);
};

Matrix operator+(const Matrix& a, const Matrix& b);
Matrix operator+(const Matrix& a, double number);
Matrix operator+(double number, const Matrix& b);

Matrix operator-(const Matrix& a, const Matrix& b);
Matrix operator-(const Matrix& a, double number);
Matrix operator-(double number, const Matrix& b);

Matrix operator*(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, double number);
Matrix operator*(double number, const Matrix& b);

#endif
