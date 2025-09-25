#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    [[nodiscard]] virtual double area() const = 0;

    virtual ~Shape() = default;
};

#endif