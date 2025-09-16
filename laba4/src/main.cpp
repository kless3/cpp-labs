#include <iostream>
#include <vector>
#include <memory>
#include "../include/Shape.h"
#include "../include/Rectangle.h"
#include "../include/Circle.h"
#include "../include/RightTriangle.h"
#include "../include/Trapezoid.h"

using namespace std;

int main() {
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(make_unique<Circle>(2.5));
    shapes.push_back(make_unique<RightTriangle>(4.0, 3.0));
    shapes.push_back(make_unique<Trapezoid>(3.0, 5.0, 4.0));

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
            for (size_t i = 0; i < shapes.size(); ++i) {
                cout << "Shape " << i + 1 << ": " << shapes[i]->area() << endl;
            }
        } else if (choice == 2) {
            double w;
            double h;
            cout << "Enter width and height: ";
            cin >> w >> h;
            shapes.push_back(make_unique<Rectangle>(w, h));
        } else if (choice == 3) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            shapes.push_back(make_unique<Circle>(r));
        } else if (choice == 4) {
            double b;
            double h;
            cout << "Enter base and height: ";
            cin >> b >> h;
            shapes.push_back(make_unique<RightTriangle>(b, h));
        } else if (choice == 5) {
            double a;
            double b;
            double h;
            cout << "Enter base1, base2 and height: ";
            cin >> a >> b >> h;
            shapes.push_back(make_unique<Trapezoid>(a, b, h));
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}