#include <iostream>
#include "../include/Circle.h"
#include "../include/Square.h"
#include "../include/Triangle.h"

using namespace std;

void printMenu() {
    cout << "\n=== Menu ===" << endl;
    cout << "1. Circle vs Circle" << endl;
    cout << "2. Circle vs Square" << endl;
    cout << "3. Circle vs Triangle" << endl;
    cout << "4. Square vs Square" << endl;
    cout << "5. Square vs Triangle" << endl;
    cout << "6. Triangle vs Triangle" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}

int main() {
    int choice;

    do {
        printMenu();
        cin >> choice;

        Shape* shape1 = nullptr;
        Shape* shape2 = nullptr;
        bool result = false;

        switch(choice) {
            case 1:
                shape1 = new Circle();
                shape2 = new Circle();
                result = shape1->intersect(shape2);
                cout << "Circle vs Circle: " << (result ? "Intersect" : "No intersect") << endl;
                break;
            case 2:
                shape1 = new Circle();
                shape2 = new Square();
                result = shape1->intersect(shape2);
                cout << "Circle vs Square: " << (result ? "Intersect" : "No intersect") << endl;
                break;
            case 3:
                shape1 = new Circle();
                shape2 = new Triangle();
                result = shape1->intersect(shape2);
                cout << "Circle vs Triangle: " << (result ? "Intersect" : "No intersect") << endl;
                break;
            case 4:
                shape1 = new Square();
                shape2 = new Square();
                result = shape1->intersect(shape2);
                cout << "Square vs Square: " << (result ? "Intersect" : "No intersect") << endl;
                break;
            case 5:
                shape1 = new Square();
                shape2 = new Triangle();
                result = shape1->intersect(shape2);
                cout << "Square vs Triangle: " << (result ? "Intersect" : "No intersect") << endl;
                break;
            case 6:
                shape1 = new Triangle();
                shape2 = new Triangle();
                result = shape1->intersect(shape2);
                cout << "Triangle vs Triangle: " << (result ? "Intersect" : "No intersect") << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

        delete shape1;
        delete shape2;

    } while(choice != 0);

    return 0;
}