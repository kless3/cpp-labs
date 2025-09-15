#include "../include/Circle.h"

bool Circle::intersect(const Shape* other) const {
    return other->intersectWith(this);
}

bool Circle::intersectWith(const Circle* circle) const {
    return true;
}

bool Circle::intersectWith(const Square* square) const {
    return true;
}

bool Circle::intersectWith(const Triangle* triangle) const {
    return true;
}