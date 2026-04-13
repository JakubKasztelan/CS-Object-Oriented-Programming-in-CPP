#include "Poly.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(PolyTests, init) {
    Poly a(1);

    EXPECT_EQ(a.coeffs[0], 1);
}

TEST(PolyTests, insertAccessOperator) {
    Poly a(1);

    a[1] = 7;
    a[5] = 5;

    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 7);
    EXPECT_EQ(a[5], 5);
    EXPECT_EQ(a[2], 0);
}

TEST(PolyTests, positionCalculation) {
    Poly a(1);

    a[1] = 5;
    a[2] = 1;

    EXPECT_EQ(a(1), 7);
    EXPECT_EQ(a(2), 15);
}

TEST(PolyTests, addition) {
    Poly a(1);

    a[1] = 5;
    a[2] = 1;

    Poly b;

    b[1] = 3;
    b[3] = 10;

    Poly c = a + b;

    EXPECT_EQ(c[0], 1);
    EXPECT_EQ(c[1], 8);
    EXPECT_EQ(c[2], 1);
    EXPECT_EQ(c[3], 10);
}

TEST(PolyTests, subtraction) {
    Poly a(1);

    a[1] = 5;
    a[2] = 1;

    Poly b;

    b[1] = 3;
    b[3] = 10;

    Poly c = a - b;

    EXPECT_EQ(c[0], 1);
    EXPECT_EQ(c[1], 2);
    EXPECT_EQ(c[2], 1);
    EXPECT_EQ(c[3], -10);
}

TEST(PolyTests, multiplication) {
    Poly a;
    a[0] = 2;
    a[1] = 3;

    Poly b;
    b[0] = 1;
    b[1] = 4;

    Poly c = a * b;

    EXPECT_EQ(c[0], 2);
    EXPECT_EQ(c[1], 11);
    EXPECT_EQ(c[2], 12);
    EXPECT_EQ(c[3], 0);
}

TEST(PolyTests, streamInsertion) {
    Poly p;
    p[0] = 2;
    p[1] = -3;
    p[3] = 5;

    std::ostringstream oss;
    oss << p;

    std::string expected = "5x^3 - 3x + 2";
    EXPECT_EQ(oss.str(), expected);

    Poly zeroPoly;
    std::ostringstream ossZero;
    ossZero << zeroPoly;
    EXPECT_EQ(ossZero.str(), "");
}

TEST(PolyTests, passByValue) {
    Poly original;
    original[0] = 1;
    original[2] = 5;

    Poly copy = original;

    copy[0] = 10;
    copy[2] = 20;

    EXPECT_EQ(original[0], 1);
    EXPECT_EQ(original[2], 5);

    EXPECT_EQ(copy[0], 10);
    EXPECT_EQ(copy[2], 20);
}
