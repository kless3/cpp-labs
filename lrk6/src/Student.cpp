#include "../include/Student.h"
#include <iostream>
#include <sstream>

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

[[maybe_unused]] void Student::setFullName(std::string_view name) {
    fullName = name;
}

[[maybe_unused]] void Student::setBirthYear(int year) {
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

[[maybe_unused]] std::string Student::getFullName() const {
    return fullName;
}

[[maybe_unused]] int Student::getBirthYear() const {
    return birthYear;
}

[[maybe_unused]] const int* Student::getExamResults() const {
    return examResults;
}

[[maybe_unused]] int Student::getExamsCount() const {
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
    std::cout << "Студент: " << fullName << std::endl;
    std::cout << "Год рождения: " << birthYear << std::endl;
    std::cout << "Результаты экзаменов: ";

    if (examsCount > 0 && examResults) {
        for (int i = 0; i < examsCount; ++i) {
            std::cout << examResults[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Средний балл: " << calculateAverage() << std::endl;
    } else {
        std::cout << "Нет результатов" << std::endl;
    }
}
void Student::saveToFile(std::ofstream& file) const {
    file << fullName << std::endl;
    file << birthYear << std::endl;
    file << getFacultyName() << std::endl;

    file << examsCount << std::endl;
    for (int i = 0; i < examsCount; ++i) {
        file << examResults[i];
        if (i < examsCount - 1) {
            file << " ";
        }
    }
    file << std::endl;
}

void Student::loadFromFile(std::ifstream& file) {
    std::getline(file, fullName);

    std::string yearStr;
    std::getline(file, yearStr);
    birthYear = std::stoi(yearStr);

    std::string faculty;
    std::getline(file, faculty);
    setFacultyName(faculty);

    std::string countStr;
    std::getline(file, countStr);
    examsCount = std::stoi(countStr);

    delete[] examResults;

    if (examsCount > 0) {
        examResults = new int[examsCount];
        std::string resultsLine;
        std::getline(file, resultsLine);

        std::istringstream iss(resultsLine);
        for (int i = 0; i < examsCount; ++i) {
            iss >> examResults[i];
        }
    } else {
        examResults = nullptr;
    }
}