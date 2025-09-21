#include "../include/Menu.h"
#include <iostream>

const int EXIT_OPTION = 3;

int main() {
    Student *students = nullptr;
    int studentCount = 0;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;

            case 2:
                displayStudents(students, studentCount);
                break;

            case 3:
                std::cout << "Exiting program..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != EXIT_OPTION);

    delete[] students;
    return 0;
}
