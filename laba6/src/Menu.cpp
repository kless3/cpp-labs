#include "../include/Menu.h"
#include "../include/IndexOutOfBoundsException.h"
#include <iostream>

using namespace std;

void handleArrayElementAccess(const SafeArray& array) {
    int index;
    cout << "Enter index to access: ";
    cin >> index;

    try {
        int value = array[index];
        cout << "Element at index " << index << ": " << value << endl;
    } catch (const IndexOutOfBoundsException& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void displayArrayElements(const SafeArray& array) {
    cout << "Array elements: ";
    for (int i = 0; i < array.getSize(); ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void handleArrayMenu(const SafeArray& array) {
    while (true) {
        cout << "1. Access element by index" << endl;
        cout << "2. Display all elements" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                handleArrayElementAccess(array);
                break;

            case 2:
                displayArrayElements(array);
                break;

            case 3:
                return;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}

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

        handleArrayMenu(array);

    } catch (const std::invalid_argument& e) {
        cout << "Error creating array: " << e.what() << endl;
    } catch (const std::bad_alloc& e) {
        cout << "Memory allocation error: " << e.what() << endl;
    }
}

void displayMainMenu() {
    cout << "1. Work with safe array" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
}