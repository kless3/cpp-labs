#include <iostream>
#include <span>
#include "../include/Shape.h"
#include "../include/Menu.h"

const int EXIT_OPTION = 6;

using namespace std;

int main() {
    Shape **shapes = nullptr;
    int shapeCount = 0;
    int capacity = 0;

    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                showAllAreas(std::span<Shape *>(shapes, shapeCount));
                break;
            case 2:
                addRectangle(&shapes, &shapeCount, &capacity);
                break;
            case 3:
                addCircle(&shapes, &shapeCount, &capacity);
                break;
            case 4:
                addRightTriangle(&shapes, &shapeCount, &capacity);
                break;
            case 5:
                addTrapezoid(&shapes, &shapeCount, &capacity);
                break;
            case 6:
                cleanupMemory(shapes, shapeCount);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != EXIT_OPTION);

    return 0;
}

