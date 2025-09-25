#include "../include/Menu.h"
#include <iostream>

using namespace std;

void workWithArray() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    try {
        SafeArray array(size);

        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; ++i) {
            cin >> array[i];
        }

        while (true) {
            cout << "\n=== Array Operations ===" << endl;
            cout << "1. Access element by index" << endl;
            cout << "2. Display all elements" << endl;
            cout << "3. Back to main menu" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    int index;
                    cout << "Enter index to access: ";
                    cin >> index;

                    try {
                        int value = array[index];
                        cout << "Element at index " << index << ": " << value << endl;
                    } catch (const IndexOutOfBoundsException& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                }

                case 2:
                    cout << "Array elements: ";
                    for (int i = 0; i < array.getSize(); ++i) {
                        cout << array[i] << " ";
                    }
                    cout << endl;
                    break;

                case 3:
                    return;

                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        }
    } catch (const std::exception& e) {
        cout << "Error creating array: " << e.what() << endl;
    }
}

void displayMainMenu() {
    cout << "1. Work with safe array" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
}
