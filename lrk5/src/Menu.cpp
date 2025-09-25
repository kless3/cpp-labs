#include "../include/Menu.h"
#include "../include/Search.h"
#include <iostream>
#include <string>
#include <span>

using namespace std;

template <typename T>
void workWithSearch() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size. Using default size 5." << endl;
        size = 5;
    }

    auto array = new T[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    T key;
    cout << "Enter key to search: ";
    cin >> key;

    if (auto result = sequentialSearch(span<const T>(array, size), key); result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    delete[] array;
}

void displayMainMenu() {
    cout << "\n=== Sequential Search System ===" << endl;
    cout << "1. Search in integer array" << endl;
    cout << "2. Search in double array" << endl;
    cout << "3. Search in string array" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void handleMainMenuChoice(int choice) {
    switch (choice) {
        case 1:
            workWithSearch<int>();
            break;

        case 2:
            workWithSearch<double>();
            break;

        case 3:
            workWithSearch<string>();
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
    }
}