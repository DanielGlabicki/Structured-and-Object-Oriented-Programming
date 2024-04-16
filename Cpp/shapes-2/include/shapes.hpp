//
// Created by Daniel on 25/04/2023.
//

#ifndef SHAPES_1_COMPLEX_HPP
#define SHAPES_1_COMPLEX_HPP

#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>

const double PI = 3.141592;

class Shape{
private:
    double x_;
    double y_;
public:
    Shape(double x, double y) : x_(x), y_(y) {}
    virtual ~Shape() = default;

    virtual double area() const = 0;
};

class Square : public Shape{
private:
    double side_;
public:
    Square(double x, double y, double side) :
    Shape(x, y), side_(side) {}

    ~Square() override = default;

    double area() const override { return side_ * side_; }
};

class Circle : public Shape {
private:
    double radius_;
public:
    Circle(double x, double y, double radius) :
    Shape(x, y), radius_(radius) {}

    ~Circle() override = default;

    double area() const override { return PI * radius_ * radius_; }
};

double calculate_total_area(const std::vector<Shape*>& shapes);

#endif //SHAPES_1_COMPLEX_HPP
