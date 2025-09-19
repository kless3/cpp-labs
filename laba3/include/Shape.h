#ifndef SHAPE_H
#define SHAPE_H

class Circle;

class Square;

class Triangle;

class Shape {
public:
    virtual ~Shape() = default;

    virtual bool intersect(const Shape *other) const = 0;

    virtual bool intersectWith(const Circle *circle) const = 0;

    virtual bool intersectWith(const Square *square) const = 0;

    virtual bool intersectWith(const Triangle *triangle) const = 0;
};

#endif