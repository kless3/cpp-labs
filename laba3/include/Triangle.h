#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    bool intersect(const Shape* other) const override;
    bool intersectWith(const Circle* circle) const override;
    bool intersectWith(const Square* square) const override;
    bool intersectWith(const Triangle* triangle) const override;
};

#endif