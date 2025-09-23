#include "../include/Student.h"
#include <iostream>
#include <stdexcept>

Student::Student() : Fakultet(), birthYear(0), examResults(nullptr) {}

Student::Student(std::string_view name, int year, std::string_view faculty)
        : Fakultet(faculty), fullName(name), birthYear(year), examResults(nullptr) {}

Student::Student(const Student& other)
        : Fakultet(other), fullName(other.fullName), birthYear(other.birthYear),
          examsCount(other.examsCount) {

    if (examsCount > 0 && other.examResults) {
        examResults = new int[examsCount];
        for (int i = 0; i < examsCount; ++i) {
            examResults[i] = other.examResults[i];
        }
    } else {
        examResults = nullptr;
    }
}

Student::~Student() {
    delete[] examResults;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Fakultet::operator=(other);
        fullName = other.fullName;
        birthYear = other.birthYear;

        delete[] examResults;
        examsCount = other.examsCount;

        if (examsCount > 0 && other.examResults) {
            examResults = new int[examsCount];
            for (int i = 0; i < examsCount; ++i) {
                examResults[i] = other.examResults[i];
            }
        } else {
            examResults = nullptr;
            examsCount = 0;
        }
    }
    return *this;
}

void Student::setFullName(std::string_view name) {
    fullName = name;
}

void Student::setBirthYear(int year) {
    if (year > 1900 && year < 2100) {
        birthYear = year;
    }
}

void Student::setExamResults(const int* results, int count) {
    delete[] examResults;

    if (count > 0 && results) {
        examsCount = count;
        examResults = new int[examsCount];
        for (int i = 0; i < examsCount; ++i) {
            examResults[i] = results[i];
        }
    } else {
        examResults = nullptr;
        examsCount = 0;
    }
}

std::string Student::getFullName() const {
    return fullName;
}

int Student::getBirthYear() const {
    return birthYear;
}

const int* Student::getExamResults() const {
    return examResults;
}

int Student::getExamsCount() const {
    return examsCount;
}

double Student::calculateAverage() const {
    if (examsCount == 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < examsCount; ++i) {
        sum += examResults[i];
    }
    return sum / examsCount;
}

void Student::display() const {
    Fakultet::display();
    std::cout << "Student: " << fullName << std::endl;
    std::cout << "Birth Year: " << birthYear << std::endl;
    std::cout << "Exam Results: ";

    if (examsCount > 0 && examResults) {
        for (int i = 0; i < examsCount; ++i) {
            std::cout << examResults[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Average: " << calculateAverage() << std::endl;
    } else {
        std::cout << "No results" << std::endl;
    }
}