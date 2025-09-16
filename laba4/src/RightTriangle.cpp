#include "../include/RightTriangle.h"

RightTriangle::RightTriangle(double b, double h) : base(b), height(h) {}

double RightTriangle::area() const {
    return 0.5 * base * height;
}