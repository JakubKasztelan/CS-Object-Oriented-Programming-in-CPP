#include "Matrix.h"
#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

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

TEST(MatrixTests, LoadFromFile) {
    Matrix a;

    std::ifstream file("matrix.txt");
    ASSERT_TRUE(file.is_open()) << "Could not open matrix.txt in " << std::filesystem::current_path();

    file >> a;

    EXPECT_EQ(a.arr[0][0], 1);
    EXPECT_EQ(a.arr[0][1], 2);
    EXPECT_EQ(a.arr[1][0], 3);
    EXPECT_EQ(a.arr[1][1], 4);
}

TEST(MatrixTests, StreamInsertion) {
    Matrix a;

    std::ifstream file("matrix.txt");
    ASSERT_TRUE(file.is_open()) << "Could not open matrix.txt in " << std::filesystem::current_path();

    file >> a;

    std::stringstream sstream;
    sstream << a;

    EXPECT_EQ(sstream.str(), "1 2 \n3 4 \n");
}