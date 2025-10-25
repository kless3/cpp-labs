#include "../include/StudentFile.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <utility>

StudentFile::StudentFile(std::string  filename) : filename(std::move(filename)) {}

Student StudentFile::operator[](int index) const {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("Не удалось открыть файл: " + filename);
    }

    std::string countStr;
    std::getline(file, countStr);
    if (int studentCount = std::stoi(countStr); index < 0 || index >= studentCount) {
        file.close();
        throw std::out_of_range("Индекс студента вне диапазона");
    }

    file.seekg(0, std::ios::beg);
    std::getline(file, countStr);

    int studentCount = std::stoi(countStr);
    auto* students = new Student[studentCount];

    for (int i = 0; i < studentCount; i++) {
        students[i].loadFromFile(file);
    }

    file.close();

    auto result = students[index];
    delete[] students;

    return result;
}

int StudentFile::getStudentCount() const {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof()) {
        return 0;
    }

    std::string countStr;
    std::getline(file, countStr);
    file.close();

    return std::stoi(countStr);
}