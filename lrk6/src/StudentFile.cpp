#include "../include/StudentFile.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <utility>

StudentFile::StudentFile(std::string  filename) : filename(std::move(filename)) {}

Student StudentFile::operator[](int index) const {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    std::string countStr;
    std::getline(file, countStr);
    int studentCount = std::stoi(countStr);

    if (index < 0 || index >= studentCount) {
        file.close();
        throw std::out_of_range("Индекс студента вне диапазона: " + std::to_string(index));
    }

    for (int i = 0; i <= index; i++) {
        Student student;

        std::string name;
        std::getline(file, name);
        student.setFullName(name);

        std::string yearStr;
        std::getline(file, yearStr);
        student.setBirthYear(std::stoi(yearStr));

        std::string faculty;
        std::getline(file, faculty);
        student.setFacultyName(faculty);

        std::string examCountStr;
        std::getline(file, examCountStr);
        int examCount = std::stoi(examCountStr);

        if (examCount > 0) {
            std::string resultsLine;
            std::getline(file, resultsLine);

            int* results = new int[examCount];
            std::istringstream iss(resultsLine);
            for (int j = 0; j < examCount; ++j) {
                iss >> results[j];
            }

            student.setExamResults(results, examCount);
            delete[] results;
        }

        if (i == index) {
            file.close();
            return student;
        }
    }

    file.close();
    throw std::runtime_error("Студент не найден");
}

int StudentFile::getStudentCount() const {
    std::ifstream file(filename);
    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof()) {
        return 0;
    }

    int studentCount;
    file >> studentCount;
    file.close();
    return studentCount;
}