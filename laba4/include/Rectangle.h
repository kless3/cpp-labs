#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h);

    [[nodiscard]] double area() const override;
};

#endif