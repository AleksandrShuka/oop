#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <shapes.h>

using namespace testing;

TEST(ShapeTest, id)
{
    Rectangle a(1,1);
    EXPECT_EQ(a.getId(), 1);
    Square b(1, 1);
    EXPECT_EQ(b.getId(), 2);
    Ellipse c(1, 1);
    EXPECT_EQ(c.getId(), 3);
}

TEST(RectangleTest, Constructor)
{
    Rectangle s(1,2,3,4,5,0xDEADB33F);
    EXPECT_DOUBLE_EQ(s.getLength(), 1);
    EXPECT_DOUBLE_EQ(s.getWidth(), 2);
    double x, y;
    s.getPosition(x,y);
    EXPECT_DOUBLE_EQ(x, 3);
    EXPECT_DOUBLE_EQ(y, 4);
    EXPECT_DOUBLE_EQ(s.getAngle(), fmod(5, 2 * M_PI));
    EXPECT_EQ(s.getColor(), 0xDEADB33F);
}

TEST(RectangleTest, Area)
{
    Rectangle a(3,5.2);
    EXPECT_DOUBLE_EQ(a.getArea(), 15.6);
    Rectangle b(0, 999);
    EXPECT_DOUBLE_EQ(b.getArea(), 0);
}

TEST(RectangleTest, Perimeter)
{
    Rectangle a(3,5.2);
    EXPECT_DOUBLE_EQ(a.getPerimeter(), 16.4);
    Rectangle b(0, 999);
    EXPECT_DOUBLE_EQ(b.getPerimeter(), 1998);
}

TEST(RectangleTest, Stretch)
{
    Rectangle a(3,5.2);
    a.stretch(4.8);
    EXPECT_DOUBLE_EQ(a.getLength(), 14.4);
    EXPECT_DOUBLE_EQ(a.getWidth(), 24.96);
    a.stretchLength(2);
    EXPECT_DOUBLE_EQ(a.getLength(), 28.8);
    a.stretchWidth(3);
    EXPECT_DOUBLE_EQ(a.getWidth(), 74.88);
}

TEST(SquareTest, Constructor)
{
    Square s(15,3,4,5,0xDEADB33F);
    EXPECT_DOUBLE_EQ(s.getLength(), 15);
    EXPECT_DOUBLE_EQ(s.getWidth(), 15);
    double x, y;
    s.getPosition(x,y);
    EXPECT_DOUBLE_EQ(x, 3);
    EXPECT_DOUBLE_EQ(y, 4);
    EXPECT_DOUBLE_EQ(s.getAngle(), fmod(5, 2 * M_PI));
    EXPECT_EQ(s.getColor(), 0xDEADB33F);
}

TEST(SquareTest, Stretch)
{
    Square a(3);
    a.stretch(4.8);
    EXPECT_DOUBLE_EQ(a.getLength(), 14.4);
    EXPECT_DOUBLE_EQ(a.getWidth(), 14.4);
    a.stretchLength(2);
    EXPECT_DOUBLE_EQ(a.getLength(), 28.8);
    EXPECT_DOUBLE_EQ(a.getWidth(), 28.8);
    a.stretchWidth(3);
    EXPECT_DOUBLE_EQ(a.getLength(), 86.4);
    EXPECT_DOUBLE_EQ(a.getWidth(), 86.4);
}

TEST(EllipseTest, Area)
{
    Ellipse a(3,5.2);
    EXPECT_DOUBLE_EQ(a.getArea(), 12.252211349000193);
    Ellipse b(0, 999);
    EXPECT_DOUBLE_EQ(b.getArea(), 0);
}

TEST(EllipseTest, Perimeter)
{
    Ellipse a(3,5.2);
    EXPECT_DOUBLE_EQ(a.getPerimeter(), 13.026547657561165);
    Ellipse b(0, 999);
    EXPECT_DOUBLE_EQ(b.getPerimeter(), 999);
    Ellipse c(0, 0);
    EXPECT_DOUBLE_EQ(c.getPerimeter(), 0);
}
