#include "../include/Square.h"
#include <iostream>

bool Square::intersect(const Shape *other) const {
    std::cout << "[Square] intersect called, dispatching to other->intersectWith(this)...\n";
    return other->intersectWith(this);
}

bool Square::intersectWith(const Circle *circle) const {
    std::cout << "[Square] intersectWith(Circle) -> Square vs Circle\n";
    return true;
}

bool Square::intersectWith(const Square *square) const {
    std::cout << "[Square] intersectWith(Square) -> Square vs Square\n";
    return true;
}

bool Square::intersectWith(const Triangle *triangle) const {
    std::cout << "[Square] intersectWith(Triangle) -> Square vs Triangle\n";
    return true;
}