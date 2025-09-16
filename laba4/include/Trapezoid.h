#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Shape.h"

class Trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;
public:
    Trapezoid(double a, double b, double h);

    double area() const override;
};

#endif