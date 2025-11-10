#include "Matrix.h"
#include <gtest/gtest.h>
#include <sstream>

#define MATRIX_A_FILE "matrixA.txt"
#define MATRIX_B_FILE "matrixB.txt"


TEST(MatrixTests, Constructor) {
    Matrix matrix;
}

TEST(MatrixTests, CopyConstructor) {
    Matrix a;
    Matrix b(a);

    EXPECT_EQ(a.arr, b.arr);
    EXPECT_EQ(a.referenceCounter, b.referenceCounter);
    EXPECT_EQ(*(a.referenceCounter), 2);
}

TEST(MatrixTests, LoadFromFile) {
    Matrix a;

    a.loadFromFile(MATRIX_A_FILE);

    EXPECT_EQ(a.arr[0][0], 1);
    EXPECT_EQ(a.arr[0][1], 2);
    EXPECT_EQ(a.arr[1][0], 3);
    EXPECT_EQ(a.arr[1][1], 4);
}

TEST(MatrixTests, StreamInsertion) {
    Matrix a;

    a.loadFromFile(MATRIX_A_FILE);

    std::stringstream sstream;
    sstream << a;

    EXPECT_EQ(sstream.str(), "1 2 \n3 4 \n");
}
