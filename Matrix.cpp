#include "Matrix.h"

#define INITIAL_ROWS 10
#define INITIAL_COLUMNS 10

Matrix::Matrix() {
    capacityRow = INITIAL_ROWS;
    capacityCol = INITIAL_COLUMNS;
    sizeRow = 0;
    sizeCol = 0;
    referenceCounter = new int(1);

    arr = new double*[capacityRow];
    for (int i = 0; i < capacityRow; i++) {
        arr[i] = new double[capacityCol];
    }
}

Matrix::Matrix(Matrix& other) {
    capacityRow = other.sizeRow;
    capacityCol = other.sizeCol;
    sizeRow = other.sizeRow;
    sizeCol = other.sizeCol;

    arr = other.arr;
    referenceCounter = other.referenceCounter;
    (*referenceCounter)++;
}

Matrix& Matrix::operator=(Matrix& other) {
    capacityRow = other.sizeRow;
    capacityCol = other.sizeCol;
    sizeRow = other.sizeRow;
    sizeCol = other.sizeCol;

    if (this->arr != nullptr) {
        for (int i = 0; i < sizeRow; i++) {
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

    for (int i = 0; i < sizeRow; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    delete referenceCounter;
}

bool Matrix::operator==(const Matrix& other) const{
    if (this->sizeRow != other.sizeRow || this->sizeCol != other.sizeCol) {
        return false;
    }

    for (int i = 0; i < sizeRow; i++) {
        for (int j = 0; i < sizeCol; j++) {
            if (this->arr[i][j] != other.arr[i][j]) {
                return false;
            }
        }
    }

    return true;
}
