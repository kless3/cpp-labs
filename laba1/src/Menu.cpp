#include "../include/Menu.h"
#include "../include/ArrayOperations.h"
#include <iostream>

void displayMenu() {
    std::cout << "\n1. Intersection of arrays";
    std::cout << "\n2. Union of arrays";
    std::cout << "\n3. Exit";
    std::cout << "\nEnter your choice: ";
}

int getChoice() {
    int choice;
    std::cin >> choice;
    return choice;
}

int *createArray(int size) {
    auto arr = new int[size];
    std::cout << "Enter elements of array: ";
    for (auto i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    return arr;
}

void processIntersection() {
    auto size1 = 0;
    auto size2 = 0;

    std::cout << "Enter size of first array: ";
    std::cin >> size1;
    auto arr1 = createArray(size1);

    std::cout << "Enter size of second array: ";
    std::cin >> size2;
    auto arr2 = createArray(size2);

    ArrayOperations a1(arr1, size1);
    ArrayOperations a2(arr2, size2);

    auto result = ArrayOperations::intersection(a1, a2);
    std::cout << "Intersection: ";
    result.display();

    delete[] arr1;
    delete[] arr2;
}

void processUnion() {
    auto size1 = 0;
    auto size2 = 0;

    std::cout << "Enter size of first array: ";
    std::cin >> size1;
    auto arr1 = createArray(size1);

    std::cout << "Enter size of second array: ";
    std::cin >> size2;
    auto arr2 = createArray(size2);

    ArrayOperations a1(arr1, size1);
    ArrayOperations a2(arr2, size2);

    auto result = ArrayOperations::unionArrays(a1, a2);
    std::cout << "Union: ";
    result.display();

    delete[] arr1;
    delete[] arr2;
}

void handleChoice(int choice) {

}