#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    explicit Circle(double r);

    [[nodiscard]] double area() const override;
};

#endif