#include "Matrix.h"
#include <gtest/gtest.h>

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

TEST(MatrixTests, Comparison) {
    Matrix a;
    Matrix b(a);

    EXPECT_EQ(a == b, true);
}
