#include "Matrix.h"
#include <gtest/gtest.h>
#include <sstream>

#define MATRIX_A_FILE "matrixA.txt"
#define MATRIX_B_FILE "matrixB.txt"


TEST(MatrixTestsComparison, EqualityTrue) {
    Matrix a, b;
    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_A_FILE);
    EXPECT_TRUE(a == b);
}

TEST(MatrixTestsComparison, EqualityFalse) {
    Matrix a, b;
    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_B_FILE);
    EXPECT_FALSE(a == b);
}


TEST(MatrixTestsComparison, InequalityTrue) {
    Matrix a, b;
    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_B_FILE);
    EXPECT_TRUE(a != b);
}

TEST(MatrixTestsComparison, InequalityFalse) {
    Matrix a, b;
    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_A_FILE);
    EXPECT_FALSE(a != b);
}
