#include "../include/Menu.h"

using namespace std;

void resizeArray(Shape ***shapes, int shapeCount, int *capacity) {
    int newCapacity = (*capacity == 0) ? 10 : *capacity * 2;
    auto newShapes = new Shape *[newCapacity];

    for (int i = 0; i < shapeCount; ++i) {
        newShapes[i] = (*shapes)[i];
    }

    delete[] *shapes;
    *shapes = newShapes;
    *capacity = newCapacity;
}

void showAllAreas(std::span<Shape *> shapes) {
    cout << "\nAreas of all shapes:" << endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "Shape " << i + 1 << ": " << shapes[i]->area() << endl;
    }
}

void addRectangle(Shape ***shapes, int *shapeCount, int *capacity) {
    double w;
    double h;
    cout << "Enter width and height: ";
    cin >> w >> h;

    if (*shapeCount >= *capacity) {
        resizeArray(shapes, *shapeCount, capacity);
    }

    (*shapes)[(*shapeCount)++] = new Rectangle(w, h);
}

void addCircle(Shape ***shapes, int *shapeCount, int *capacity) {
    double r;
    cout << "Enter radius: ";
    cin >> r;

    if (*shapeCount >= *capacity) {
        resizeArray(shapes, *shapeCount, capacity);
    }

    (*shapes)[(*shapeCount)++] = new Circle(r);
}

void addRightTriangle(Shape ***shapes, int *shapeCount, int *capacity) {
    double b;
    double h;
    cout << "Enter base and height: ";
    cin >> b >> h;

    if (*shapeCount >= *capacity) {
        resizeArray(shapes, *shapeCount, capacity);
    }

    (*shapes)[(*shapeCount)++] = new RightTriangle(b, h);
}

void addTrapezoid(Shape ***shapes, int *shapeCount, int *capacity) {
    double a;
    double b;
    double h;
    cout << "Enter base1, base2 and height: ";
    cin >> a >> b >> h;

    if (*shapeCount >= *capacity) {
        resizeArray(shapes, *shapeCount, capacity);
    }

    (*shapes)[(*shapeCount)++] = new Trapezoid(a, b, h);
}

void cleanupMemory(Shape **shapes, int shapeCount) {
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }
    delete[] shapes;
    cout << "Exiting program..." << endl;
}