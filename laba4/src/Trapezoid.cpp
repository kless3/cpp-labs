#include "../include/Trapezoid.h"

Trapezoid::Trapezoid(double a, double b, double h) : base1(a), base2(b), height(h) {}

double Trapezoid::area() const {
    return (base1 + base2) * height / 2.0;
}