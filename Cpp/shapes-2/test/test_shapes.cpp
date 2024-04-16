//
// Created by Daniel on 25/04/2023.
//
#include "gtest/gtest.h"
#include "shapes.hpp"
#include <memory>

TEST(SquareTest, area) {
    Square square(0.0, 0.0, 1.0);
    EXPECT_EQ(square.area(), 1.0);

    Shape& shape = square;
    EXPECT_EQ(shape.area(), 1.0);
}

TEST(CircleTest, area) {
    Circle circle(0.0, 0.0, 1.0);
    EXPECT_EQ(circle.area(), PI);

    Shape& shape = circle;
    EXPECT_EQ(shape.area(), PI);
}
TEST(ShapesAuxTest, totalAreaOfShapeCollection){
    std::vector<std::unique_ptr<Shape>> vec;
    /*std::unique_ptr<Shape> s1 = std::make_unique<Square>(2, 4, 2);
    std::unique_ptr<Shape> c1 = std::make_unique<Circle>(1, 2, 3);

    vec.push_back(s1);  tak nie bo to unique_ptr!!!
    vec.push_back(c1);*/

    vec.push_back(std::make_unique<Square>(2, 4, 2));
    vec.push_back(std::make_unique<Circle>(1, 2, 3));

    std::vector<Shape*> shapes;
    std::transform(vec.begin(), vec.end(), std::back_inserter(shapes), [](const auto& vec_ptr){return vec_ptr.get(); });

    EXPECT_EQ(calculate_total_area(shapes), 3.0 * 3.0 * PI + 2.0 * 2.0);
}