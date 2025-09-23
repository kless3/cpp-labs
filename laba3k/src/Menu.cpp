#include "../include/Menu.h"
#include <iostream>
#include <limits>
#include <span>

void displayMenu() {
    std::cout << "1. Add new student" << std::endl;
    std::cout << "2. Display all students" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Choose option: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addStudent(Student**& students, int& studentCount) {
    std::string name;
    std::string faculty;
    int year;
    int examCount;

    std::cout << "Enter student full name: ";
    std::getline(std::cin, name);

    std::cout << "Enter birth year: ";
    std::cin >> year;
    clearInputBuffer();

    std::cout << "Enter faculty name: ";
    std::getline(std::cin, faculty);

    std::cout << "Enter number of exams: ";
    std::cin >> examCount;

    Student* newStudent = new Student(name, year, faculty);

    if (examCount > 0) {
        auto exams = new int[examCount];
        std::cout << "Enter exam results: ";
        for (int i = 0; i < examCount; ++i) {
            std::cin >> exams[i];
        }
        clearInputBuffer();
        newStudent->setExamResults(exams, examCount);
        delete[] exams;
    }

    Student** newStudents = new Student*[studentCount + 1];

    for (int i = 0; i < studentCount; ++i) {
        newStudents[i] = students[i];
    }

    newStudents[studentCount] = newStudent;

    if (students != nullptr) {
        delete[] students;
    }

    students = newStudents;
    studentCount++;

    std::cout << "Student added successfully!" << std::endl;
}

void displayStudents(Student** students, int studentCount) {
    if (studentCount == 0) {
        std::cout << "No students in the system." << std::endl;
    } else {
        for (int i = 0; i < studentCount; ++i) {
            students[i]->display();
            std::cout << "-------------------" << std::endl;
        }
    }
}