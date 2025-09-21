#include <iostream>
#include <span> // Add this include for std::span
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Circle.h"
#include "../include/RightTriangle.h"
#include "../include/Trapezoid.h"

const int EXIT_OPTION = 6;

using namespace std;

// Прототипы функций - update the prototype
void showAllAreas(std::span<Shape*> shapes);
void addRectangle(Shape*** shapes, int* shapeCount, int* capacity);
void addCircle(Shape*** shapes, int* shapeCount, int* capacity);
void addRightTriangle(Shape*** shapes, int* shapeCount, int* capacity);
void addTrapezoid(Shape*** shapes, int* shapeCount, int* capacity);
void cleanupMemory(Shape** shapes, int shapeCount);
void resizeArray(Shape*** shapes, int shapeCount, int* capacity);

int main() {
    Shape** shapes = nullptr;
    int shapeCount = 0;
    int capacity = 0;

    int choice;

    do {
        cout << "1. Show all areas" << endl;
        cout << "2. Add Rectangle" << endl;
        cout << "3. Add Circle" << endl;
        cout << "4. Add Right Triangle" << endl;
        cout << "5. Add Trapezoid" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Update the call to use std::span
                showAllAreas(std::span<Shape*>(shapes, shapeCount));
                break;
            case 2: addRectangle(&shapes, &shapeCount, &capacity); break;
            case 3: addCircle(&shapes, &shapeCount, &capacity); break;
            case 4: addRightTriangle(&shapes, &shapeCount, &capacity); break;
            case 5: addTrapezoid(&shapes, &shapeCount, &capacity); break;
            case 6: cleanupMemory(shapes, shapeCount); break;
            default: cout << "Invalid choice!" << endl; break;
        }
    } while (choice != EXIT_OPTION);

    return 0;
}

// Функция для изменения размера массива
void resizeArray(Shape*** shapes, int shapeCount, int* capacity) {
    int newCapacity = (*capacity == 0) ? 10 : *capacity * 2;
    Shape** newShapes = new Shape*[newCapacity];

    for (int i = 0; i < shapeCount; ++i) {
        newShapes[i] = (*shapes)[i];
    }

    delete[] *shapes;
    *shapes = newShapes;
    *capacity = newCapacity;
}

// Функция для отображения всех площадей - updated with std::span
void showAllAreas(std::span<Shape*> shapes) {
    cout << "\nAreas of all shapes:" << endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "Shape " << i + 1 << ": " << shapes[i]->area() << endl;
    }
}

// Остальные функции остаются без изменений
void addRectangle(Shape*** shapes, int* shapeCount, int* capacity) {
    double w;
    double h;
    cout << "Enter width and height: ";
    cin >> w >> h;

    if (*shapeCount >= *capacity) {
        resizeArray(shapes, *shapeCount, capacity);
    }

    (*shapes)[(*shapeCount)++] = new Rectangle(w, h);
}

void addCircle(Shape*** shapes, int* shapeCount, int* capacity) {
    double r;
    cout << "Enter radius: ";
    cin >> r;

    if (*shapeCount >= *capacity) {
        resizeArray(shapes, *shapeCount, capacity);
    }

    (*shapes)[(*shapeCount)++] = new Circle(r);
}

void addRightTriangle(Shape*** shapes, int* shapeCount, int* capacity) {
    double b;
    double h;
    cout << "Enter base and height: ";
    cin >> b >> h;

    if (*shapeCount >= *capacity) {
        resizeArray(shapes, *shapeCount, capacity);
    }

    (*shapes)[(*shapeCount)++] = new RightTriangle(b, h);
}

void addTrapezoid(Shape*** shapes, int* shapeCount, int* capacity) {
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

void cleanupMemory(Shape** shapes, int shapeCount) {
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }
    delete[] shapes;
    cout << "Exiting program..." << endl;
}