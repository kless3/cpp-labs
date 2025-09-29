#include "../include/Triangle.h"
#include <iostream>

bool Triangle::intersect(const Shape *other) const {
    std::cout << "[Triangle] intersect called, dispatching to other->intersectWith(this)...\n";
    return other->intersectWith(this);
}

bool Triangle::intersectWith(const Circle *circle) const {
    std::cout << "[Triangle] intersectWith(Circle) -> Triangle vs Circle\n";
    return true;
}

bool Triangle::intersectWith(const Square *square) const {
    std::cout << "[Triangle] intersectWith(Square) -> Triangle vs Square\n";
    return true;
}

bool Triangle::intersectWith(const Triangle *triangle) const {
    std::cout << "[Triangle] intersectWith(Triangle) -> Triangle vs Triangle\n";
    return true;
}