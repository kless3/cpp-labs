#include <iostream>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Circle.h"
#include "../include/RightTriangle.h"
#include "../include/Trapezoid.h"

using namespace std;

int main() {
    Shape** shapes = nullptr;  // Указатель на массив указателей
    int shapeCount = 0;
    int capacity = 0;

    int choice;

    while (true) {
        cout << "1. Show all areas" << endl;
        cout << "2. Add Rectangle" << endl;
        cout << "3. Add Circle" << endl;
        cout << "4. Add Right Triangle" << endl;
        cout << "5. Add Trapezoid" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nAreas of all shapes:" << endl;
            for (int i = 0; i < shapeCount; ++i) {
                cout << "Shape " << i + 1 << ": " << shapes[i]->area() << endl;
            }
        } else if (choice == 2) {
            double w, h;
            cout << "Enter width and height: ";
            cin >> w >> h;

            // Увеличиваем емкость массива при необходимости
            if (shapeCount >= capacity) {
                int newCapacity = (capacity == 0) ? 10 : capacity * 2;
                Shape** newShapes = new Shape*[newCapacity];

                // Копируем существующие указатели
                for (int i = 0; i < shapeCount; ++i) {
                    newShapes[i] = shapes[i];
                }

                // Освобождаем старый массив
                delete[] shapes;
                shapes = newShapes;
                capacity = newCapacity;
            }

            shapes[shapeCount++] = new Rectangle(w, h);

        } else if (choice == 3) {
            double r;
            cout << "Enter radius: ";
            cin >> r;

            if (shapeCount >= capacity) {
                int newCapacity = (capacity == 0) ? 10 : capacity * 2;
                Shape** newShapes = new Shape*[newCapacity];

                for (int i = 0; i < shapeCount; ++i) {
                    newShapes[i] = shapes[i];
                }

                delete[] shapes;
                shapes = newShapes;
                capacity = newCapacity;
            }

            shapes[shapeCount++] = new Circle(r);

        } else if (choice == 4) {
            double b, h;
            cout << "Enter base and height: ";
            cin >> b >> h;

            if (shapeCount >= capacity) {
                int newCapacity = (capacity == 0) ? 10 : capacity * 2;
                Shape** newShapes = new Shape*[newCapacity];

                for (int i = 0; i < shapeCount; ++i) {
                    newShapes[i] = shapes[i];
                }

                delete[] shapes;
                shapes = newShapes;
                capacity = newCapacity;
            }

            shapes[shapeCount++] = new RightTriangle(b, h);

        } else if (choice == 5) {
            double a, b, h;
            cout << "Enter base1, base2 and height: ";
            cin >> a >> b >> h;

            if (shapeCount >= capacity) {
                int newCapacity = (capacity == 0) ? 10 : capacity * 2;
                Shape** newShapes = new Shape*[newCapacity];

                for (int i = 0; i < shapeCount; ++i) {
                    newShapes[i] = shapes[i];
                }

                delete[] shapes;
                shapes = newShapes;
                capacity = newCapacity;
            }

            shapes[shapeCount++] = new Trapezoid(a, b, h);

        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    // Освобождаем память перед выходом
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }
    delete[] shapes;

    return 0;
}