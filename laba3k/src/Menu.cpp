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

void addStudent(std::span<Student>& studentsSpan, int& studentCount) {
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

    Student* students = studentsSpan.data();

    if (examCount > 0) {
        auto exams = new int[examCount];
        std::cout << "Enter exam results: ";
        for (int i = 0; i < examCount; ++i) {
            std::cin >> exams[i];
        }
        clearInputBuffer();

        auto temp = new Student[studentCount + 1];
        for (int i = 0; i < studentCount; ++i) {
            temp[i] = students[i];
        }

        temp[studentCount] = Student(name, year, faculty);
        temp[studentCount].setExamResults(exams, examCount);

        delete[] students;
        delete[] exams;

        students = temp;
        studentCount++;

        studentsSpan = std::span<Student>(students, studentCount);

        std::cout << "Student added successfully!" << std::endl;
    } else {
        auto temp = new Student[studentCount + 1];
        for (int i = 0; i < studentCount; ++i) {
            temp[i] = students[i];
        }

        temp[studentCount] = Student(name, year, faculty);

        delete[] students;
        students = temp;
        studentCount++;

        studentsSpan = std::span<Student>(students, studentCount);

        std::cout << "Student added successfully!" << std::endl;
    }
}

void displayStudents(std::span<Student> studentsSpan) {
    if (studentsSpan.empty()) {
        std::cout << "No students in the system." << std::endl;
    } else {
        for (const auto& student : studentsSpan) {
            student.display();
        }
    }
}