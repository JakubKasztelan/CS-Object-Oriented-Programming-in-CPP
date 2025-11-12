#include "Matrix.h"
#include "MatrixExceptions.h"

#include <gtest/gtest.h>

#define MATRIX_A_FILE "matrixA.txt"
#define MATRIX_B_FILE "matrixB.txt"
#define MATRIX_C_FILE "matrixC.txt"
#define MATRIX_D_FILE "matrixD.txt"

TEST(MatrixTestsExceptions, FileReadException) {
    Matrix a;

    EXPECT_THROW(a.loadFromFile("wrongfilename.txt"), FileReadException);
}

TEST(MatrixTestsExceptions, SizeException) {
    Matrix a;
    a.loadFromFile(MATRIX_A_FILE);

    Matrix c;
    c.loadFromFile(MATRIX_C_FILE);

    EXPECT_THROW(a += c, SizeException);
}

TEST(MatrixTestsExceptions, MatrixReadException) {
    Matrix d;

    EXPECT_THROW(d.loadFromFile(MATRIX_D_FILE), MatrixReadException);
}