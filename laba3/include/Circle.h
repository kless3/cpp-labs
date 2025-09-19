#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    bool intersect(const Shape *other) const override;

    bool intersectWith(const Circle *circle) const override;

    bool intersectWith(const Square *square) const override;

    bool intersectWith(const Triangle *triangle) const override;
};

#endif