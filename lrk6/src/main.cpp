#include "../include/Menu.h"
#include <iostream>
#include <span>
#include <windows.h>

const int EXIT_OPTION = 6;
const std::string DATA_FILE = "students.txt";

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
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
                saveStudentsToFile(DATA_FILE, studentsSpan);
                break;

            case 4:
                loadStudentsFromFile(DATA_FILE, studentsSpan, studentCount);
                students = studentsSpan.data();
                break;

            case 5:
                demonstrateFileIndexing(DATA_FILE);
                break;

            case 6:
                std::cout << "Выход из программы..." << std::endl;
                break;

            default:
                std::cout << "Неправильный выбор. Попробуйте еще раз." << std::endl;
        }
    } while (choice != EXIT_OPTION);

    for (int i = 0; i < studentCount; ++i) {
        delete students[i];
    }
    delete[] students;

    return 0;
}