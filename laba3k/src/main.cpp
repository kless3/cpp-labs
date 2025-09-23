#include "../include/Menu.h"
#include <iostream>
#include <span>

const int EXIT_OPTION = 3;

int main() {
    Student** students = nullptr;
    int studentCount = 0;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        std::span<Student*> studentsSpan(students, studentCount);

        switch (choice) {
            case 1:
                addStudent(studentsSpan, studentCount);
                students = studentsSpan.data();
                break;

            case 2:
                displayStudents(studentsSpan);
                break;

            case 3:
                std::cout << "Exiting program..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != EXIT_OPTION);

    for (int i = 0; i < studentCount; ++i) {
        delete students[i];
    }
    delete[] students;

    return 0;
}