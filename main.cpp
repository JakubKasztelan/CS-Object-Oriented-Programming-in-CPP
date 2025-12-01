#include "Polygon.h"
#include <gtest/gtest.h>

TEST(PolygonTest, DefaultConstructor) {
    Polygon poly;
    EXPECT_EQ(poly.vertexCount(), 0);
}

TEST(PolygonTest, VectorConstructor) {
    std::vector<Point> points = {{0,0}, {1,0}, {1,1}, {0,1}};
    Polygon poly(points);
    EXPECT_EQ(poly.vertexCount(), 4);
    EXPECT_EQ(poly[0].x, 0);
    EXPECT_EQ(poly[0].y, 0);
}

TEST(PolygonTest, InitializerListConstructor) {
    Polygon poly = {{0,0}, {2,0}, {2,2}, {0,2}};
    EXPECT_EQ(poly.vertexCount(), 4);
    EXPECT_EQ(poly[1].x, 2);
    EXPECT_EQ(poly[1].y, 0);
}

TEST(PolygonTest, OperatorIndex) {
    Polygon poly = {{0,0}, {1,1}};
    poly[0].x = 5;
    poly[0].y = 10;
    EXPECT_EQ(poly[0].x, 5);
    EXPECT_EQ(poly[0].y, 10);
}

TEST(PolygonTest, OperatorPlusEqualsTranslate) {
    Polygon poly = {{0,0}, {1,1}};
    poly += Point{2, 3};
    EXPECT_DOUBLE_EQ(poly[0].x, 2);
    EXPECT_DOUBLE_EQ(poly[0].y, 3);
    EXPECT_DOUBLE_EQ(poly[1].x, 3);
    EXPECT_DOUBLE_EQ(poly[1].y, 4);
}

TEST(PolygonTest, OperatorMinusEqualsTranslate) {
    Polygon poly = {{2,3}, {4,5}};
    poly -= Point{1, 1};
    EXPECT_DOUBLE_EQ(poly[0].x, 1);
    EXPECT_DOUBLE_EQ(poly[0].y, 2);
    EXPECT_DOUBLE_EQ(poly[1].x, 3);
    EXPECT_DOUBLE_EQ(poly[1].y, 4);
}

TEST(PolygonTest, OperatorEquality) {
    Polygon poly1 = {{0,0}, {1,1}};
    Polygon poly2 = {{0,0}, {1,1}};
    Polygon poly3 = {{1,0}, {1,1}};
    EXPECT_TRUE(poly1 == poly2);
    EXPECT_FALSE(poly1 == poly3);
}

TEST(PolygonTest, PerimeterSquare) {
    Polygon poly = {{0,0}, {1,0}, {1,1}, {0,1}};
    EXPECT_DOUBLE_EQ(poly.perimeter(), 4.0);
}

TEST(PolygonTest, AreaSquare) {
    Polygon poly = {{0,0}, {1,0}, {1,1}, {0,1}};
    EXPECT_DOUBLE_EQ(poly.area(), 1.0);
}

TEST(PolygonTest, VertexCount) {
    Polygon poly = {{0,0}, {1,0}, {1,1}};
    EXPECT_EQ(poly.vertexCount(), 3);
}