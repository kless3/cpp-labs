#include "../include/Triangle.h"

bool Triangle::intersect(const Shape* other) const {
    return other->intersectWith(this);
}

bool Triangle::intersectWith(const Circle* circle) const {
    return true;
}

bool Triangle::intersectWith(const Square* square) const {
    return true;
}

bool Triangle::intersectWith(const Triangle* triangle) const {
    return true;
}