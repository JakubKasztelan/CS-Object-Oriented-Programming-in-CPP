#include "Matrix.h"
#include <gtest/gtest.h>
#include <sstream>

#define MATRIX_A_FILE "matrixA.txt"
#define MATRIX_B_FILE "matrixB.txt"

#define NUMBER_ADD 5.3
#define NUMBER_ADD_2 3.0
#define NUMBER_SUB 2.5
#define NUMBER_SUB_2 1.0
#define NUMBER_MUL 2.0
#define NUMBER_MUL_2 3.0


TEST(MatrixTestsArithmetic, CompoundAdditionMatrix) {
    Matrix a;
    Matrix b;

    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_B_FILE);

    a += b;

    EXPECT_EQ(a.arr[0][0], 1);
    EXPECT_EQ(a.arr[0][1], 7);
    EXPECT_EQ(a.arr[1][0], 7);
    EXPECT_EQ(a.arr[1][1], 7);
}

TEST(MatrixTestsArithmetic, CompoundAdditionNumber) {
    Matrix a;
    double number = NUMBER_ADD;

    a.loadFromFile(MATRIX_A_FILE);

    a += number;

    EXPECT_EQ(a.arr[0][0], 6.3);
    EXPECT_EQ(a.arr[0][1], 7.3);
    EXPECT_EQ(a.arr[1][0], 8.3);
    EXPECT_EQ(a.arr[1][1], 9.3);
}

TEST(MatrixTestsArithmetic, CompoundSubtractionMatrix) {
    Matrix a;
    Matrix b;

    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_B_FILE);

    a -= b;

    EXPECT_EQ(a.arr[0][0], 1);
    EXPECT_EQ(a.arr[0][1], -3);
    EXPECT_EQ(a.arr[1][0], -1);
    EXPECT_EQ(a.arr[1][1], 1);
}

TEST(MatrixTestsArithmetic, CompoundSubtractionNumber) {
    Matrix a;
    double number = NUMBER_SUB;

    a.loadFromFile(MATRIX_A_FILE);

    a -= number;

    EXPECT_EQ(a.arr[0][0], -1.5);
    EXPECT_EQ(a.arr[0][1], -0.5);
    EXPECT_EQ(a.arr[1][0], 0.5);
    EXPECT_EQ(a.arr[1][1], 1.5);
}

TEST(MatrixTestsArithmetic, CompoundMultiplicationMatrix) {
    Matrix a;
    Matrix b;

    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_B_FILE);

    a *= b;

    EXPECT_EQ(a.arr[0][0], 8);
    EXPECT_EQ(a.arr[0][1], 11);
    EXPECT_EQ(a.arr[1][0], 16);
    EXPECT_EQ(a.arr[1][1], 27);
}

TEST(MatrixTestsArithmetic, CompoundMultiplicationNumber) {
    Matrix a;
    double number = NUMBER_MUL;

    a.loadFromFile(MATRIX_A_FILE);

    a *= number;

    EXPECT_EQ(a.arr[0][0], 2);
    EXPECT_EQ(a.arr[0][1], 4);
    EXPECT_EQ(a.arr[1][0], 6);
    EXPECT_EQ(a.arr[1][1], 8);
}

TEST(MatrixTestsArithmetic, AdditionMatrix) {
    Matrix a;
    Matrix b;

    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_B_FILE);

    Matrix c = a + b;

    EXPECT_EQ(c.arr[0][0], 1);
    EXPECT_EQ(c.arr[0][1], 7);
    EXPECT_EQ(c.arr[1][0], 7);
    EXPECT_EQ(c.arr[1][1], 7);
}

TEST(MatrixTestsArithmetic, AdditionNumber) {
    Matrix a;
    double number = NUMBER_ADD_2;

    a.loadFromFile(MATRIX_A_FILE);

    Matrix c = a + number;

    EXPECT_EQ(c.arr[0][0], 4);
    EXPECT_EQ(c.arr[0][1], 5);
    EXPECT_EQ(c.arr[1][0], 6);
    EXPECT_EQ(c.arr[1][1], 7);
}

TEST(MatrixTestsArithmetic, SubtractionMatrix) {
    Matrix a;
    Matrix b;

    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_B_FILE);

    Matrix c = a - b;

    EXPECT_EQ(c.arr[0][0], 1);
    EXPECT_EQ(c.arr[0][1], -3);
    EXPECT_EQ(c.arr[1][0], -1);
    EXPECT_EQ(c.arr[1][1], 1);
}

TEST(MatrixTestsArithmetic, SubtractionNumber) {
    Matrix a;
    double number = NUMBER_SUB_2;

    a.loadFromFile(MATRIX_A_FILE);

    Matrix c = a - number;

    EXPECT_EQ(c.arr[0][0], 0);
    EXPECT_EQ(c.arr[0][1], 1);
    EXPECT_EQ(c.arr[1][0], 2);
    EXPECT_EQ(c.arr[1][1], 3);
}

TEST(MatrixTestsArithmetic, MultiplicationMatrix) {
    Matrix a;
    Matrix b;

    a.loadFromFile(MATRIX_A_FILE);
    b.loadFromFile(MATRIX_B_FILE);

    Matrix c = a * b;

    EXPECT_EQ(c.arr[0][0], 8);
    EXPECT_EQ(c.arr[0][1], 11);
    EXPECT_EQ(c.arr[1][0], 16);
    EXPECT_EQ(c.arr[1][1], 27);
}

TEST(MatrixTestsArithmetic, MultiplicationNumber) {
    Matrix a;
    double number = NUMBER_MUL_2;

    a.loadFromFile(MATRIX_A_FILE);

    Matrix c = a * number;

    EXPECT_EQ(c.arr[0][0], 3);
    EXPECT_EQ(c.arr[0][1], 6);
    EXPECT_EQ(c.arr[1][0], 9);
    EXPECT_EQ(c.arr[1][1], 12);
}
