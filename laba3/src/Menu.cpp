#include "../include/Menu.h"

using namespace std;

void printMenu() {
    cout << "1. Circle vs Circle" << endl;
    cout << "2. Circle vs Square" << endl;
    cout << "3. Circle vs Triangle" << endl;
    cout << "4. Square vs Square" << endl;
    cout << "5. Square vs Triangle" << endl;
    cout << "6. Triangle vs Triangle" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}

bool testCircleCircle() {
    Circle circle1, circle2;
    bool result = circle1.intersect(&circle2);
    cout << "Circle vs Circle: " << (result ? "Intersect" : "No intersect") << endl;
    return true;
}

bool testCircleSquare() {
    Circle circle;
    Square square;
    bool result = circle.intersect(&square);
    cout << "Circle vs Square: " << (result ? "Intersect" : "No intersect") << endl;
    return true;
}

bool testCircleTriangle() {
    Circle circle;
    Triangle triangle;
    bool result = circle.intersect(&triangle);
    cout << "Circle vs Triangle: " << (result ? "Intersect" : "No intersect") << endl;
    return true;
}

bool testSquareSquare() {
    Square square1, square2;
    bool result = square1.intersect(&square2);
    cout << "Square vs Square: " << (result ? "Intersect" : "No intersect") << endl;
    return true;
}

bool testSquareTriangle() {
    Square square;
    Triangle triangle;
    bool result = square.intersect(&triangle);
    cout << "Square vs Triangle: " << (result ? "Intersect" : "No intersect") << endl;
    return true;
}

bool testTriangleTriangle() {
    Triangle triangle1, triangle2;
    bool result = triangle1.intersect(&triangle2);
    cout << "Triangle vs Triangle: " << (result ? "Intersect" : "No intersect") << endl;
    return true;
}
