#include "../include/Square.h"

bool Square::intersect(const Shape* other) const {
    return other->intersectWith(this);
}

bool Square::intersectWith(const Circle* circle) const {
    return true;
}

bool Square::intersectWith(const Square* square) const {
    return true;
}

bool Square::intersectWith(const Triangle* triangle) const {
    return true;
}