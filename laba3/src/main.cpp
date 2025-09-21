#include <iostream>

#include "../include/Menu.h"

using namespace std;

int main() {
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                testCircleCircle();
                break;
            case 2:
                testCircleSquare();
                break;
            case 3:
                testCircleTriangle();
                break;
            case 4:
                testSquareSquare();
                break;
            case 5:
                testSquareTriangle();
                break;
            case 6:
                testTriangleTriangle();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}