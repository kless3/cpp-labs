#include "../include/Circle.h"
#include <iostream>

bool Circle::intersect(const Shape *other) const {
    std::cout << "[Circle] intersect called, dispatching to other->intersectWith(this)...\n";
    return other->intersectWith(this);
}

bool Circle::intersectWith(const Circle *circle) const {
    std::cout << "[Circle] intersectWith(Circle) -> Circle vs Circle\n";
    return true;
}

bool Circle::intersectWith(const Square *square) const {
    std::cout << "[Circle] intersectWith(Square) -> Circle vs Square\n";
    return true;
}

bool Circle::intersectWith(const Triangle *triangle) const {
    std::cout << "[Circle] intersectWith(Triangle) -> Circle vs Triangle\n";
    return true;
}