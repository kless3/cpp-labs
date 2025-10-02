#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <span>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Circle.h"
#include "../include/RightTriangle.h"
#include "../include/Trapezoid.h"

void showAllAreas(std::span<Shape *> shapes);

void addRectangle(Shape ***shapes, int *shapeCount, int *capacity);

void addCircle(Shape ***shapes, int *shapeCount, int *capacity);

void addRightTriangle(Shape ***shapes, int *shapeCount, int *capacity);

void addTrapezoid(Shape ***shapes, int *shapeCount, int *capacity);

void cleanupMemory(Shape **shapes, int shapeCount);

void resizeArray(Shape ***shapes, int shapeCount, int *capacity);

void printMenu();

#endif
