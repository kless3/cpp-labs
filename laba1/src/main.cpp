#include "../include/ArrayOperations.h"
#include <iostream>

int main() {
    int choice;

    do {
        std::cout << "\n1. Intersection of arrays";
        std::cout << "\n2. Union of arrays";
        std::cout << "\n3. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) {
            int size1, size2;

            std::cout << "Enter size of first array: ";
            std::cin >> size1;
            int* arr1 = new int[size1];
            std::cout << "Enter elements of first array: ";
            for (int i = 0; i < size1; i++) {
                std::cin >> arr1[i];
            }

            std::cout << "Enter size of second array: ";
            std::cin >> size2;
            int* arr2 = new int[size2];
            std::cout << "Enter elements of second array: ";
            for (int i = 0; i < size2; i++) {
                std::cin >> arr2[i];
            }

            ArrayOperations a1(arr1, size1);
            ArrayOperations a2(arr2, size2);

            if (choice == 1) {
                ArrayOperations result = ArrayOperations::intersection(a1, a2);
                std::cout << "Intersection: ";
                result.display();
            } else {
                ArrayOperations result = ArrayOperations::unionArrays(a1, a2);
                std::cout << "Union: ";
                result.display();
            }

            delete[] arr1;
            delete[] arr2;
        }
        else if (choice == 3) {
            std::cout << "Exiting program..." << std::endl;
        }
        else {
            std::cout << "Invalid choice! Try again." << std::endl;
        }

    } while (choice != 3);

    return 0;
}