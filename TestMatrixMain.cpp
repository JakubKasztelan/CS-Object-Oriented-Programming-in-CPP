#include "Matrix.h"
#include <gtest/gtest.h>
#include <sstream>

#define MATRIX_A_FILE "matrixA.txt"
#define MATRIX_B_FILE "matrixB.txt"


TEST(MatrixTestsMain, Constructor) {
    Matrix matrix;
    EXPECT_EQ(matrix.getReferenceCounter(), 1);
}

TEST(MatrixTestsMain, CopyConstructor) {
    Matrix a;
    a.loadFromFile(MATRIX_A_FILE);

    Matrix b(a);

    EXPECT_EQ(a.getReferenceCounter(), b.getReferenceCounter());
    EXPECT_EQ(a.getReferenceCounter(), 2);
    EXPECT_EQ(b(0, 0), a(0, 0));
    EXPECT_EQ(b(0, 1), a(0, 1));
    EXPECT_EQ(b(1, 0), a(1, 0));
    EXPECT_EQ(b(1, 1), a(1, 1));
}

TEST(MatrixTestsMain, CopyOperator) {
    Matrix a;
    a.loadFromFile(MATRIX_A_FILE);

    Matrix b;
    b = a;

    EXPECT_EQ(a.getReferenceCounter(), b.getReferenceCounter());
    EXPECT_EQ(a.getReferenceCounter(), 2);
    EXPECT_EQ(b(0, 0), a(0, 0));
    EXPECT_EQ(b(0, 1), a(0, 1));
    EXPECT_EQ(b(1, 0), a(1, 0));
    EXPECT_EQ(b(1, 1), a(1, 1));
}

TEST(MatrixTestsMain, SelfAssignment) {
    Matrix a;
    a.loadFromFile(MATRIX_A_FILE);

    a = a;

    EXPECT_EQ(a.getReferenceCounter(), 1);
}

TEST(MatrixTestsMain, DestructorDecrementsCounter) {
    Matrix* a = new Matrix();
    Matrix* b = new Matrix(*a);

    EXPECT_EQ(a->getReferenceCounter(), 2);

    delete b;
    EXPECT_EQ(a->getReferenceCounter(), 1);

    delete a;
}

TEST(MatrixTestsMain, LoadFromFile) {
    Matrix a;

    a.loadFromFile(MATRIX_A_FILE);

    EXPECT_EQ(a(0, 0), 1);
    EXPECT_EQ(a(0, 1), 2);
    EXPECT_EQ(a(1, 0), 3);
    EXPECT_EQ(a(1, 1), 4);
}

TEST(MatrixTestsMain, StreamInsertion) {
    Matrix a;

    a.loadFromFile(MATRIX_A_FILE);

    std::stringstream sstream;
    sstream << a;

    EXPECT_EQ(sstream.str(), "1 2 \n3 4 \n");
}

TEST(MatrixTestsMain, SingleElementAccess) {
    Matrix a;

    a.loadFromFile(MATRIX_A_FILE);

    EXPECT_EQ(a(0, 0), 1);

    a(0,0) = 5;

    EXPECT_EQ(a(0, 0), 5);

    Matrix b = a;

    b(0, 0) = 1;

    EXPECT_EQ(a(0, 0), 5);
    EXPECT_EQ(a.getReferenceCounter(), 1);
    EXPECT_EQ(b(0, 0), 1);
    EXPECT_EQ(b.getReferenceCounter(), 1);
}
