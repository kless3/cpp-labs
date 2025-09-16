#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Shape.h"

class RightTriangle : public Shape {
private:
    double base;
    double height;
public:
    RightTriangle(double b, double h);

    double area() const override;
};

#endif