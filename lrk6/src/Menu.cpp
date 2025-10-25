#include "../include/Menu.h"
#include "../include/StringValidator.h"
#include "../include/EnglishLanguageException.h"
#include <iostream>
#include <limits>
#include <span>

void displayMenu() {
    std::cout << "1. Добавить студента" << std::endl;
    std::cout << "2. Показать всех студентов" << std::endl;
    std::cout << "3. Сохранить студентов в файл" << std::endl;
    std::cout << "4. Загрузить студентов из файла" << std::endl;
    std::cout << "5. Доступ к студентам из файла через operator[]" << std::endl;
    std::cout << "6. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addStudent(std::span<Student *> &studentsSpan, int &studentCount) {
    std::string name;
    std::string faculty;
    int year;
    int examCount;

    while (true) {
        std::cout << "Введите имя студента(Только русские символы): ";
        std::getline(std::cin, name);

        try {
            StringValidator::validateEnglishText(name);
            break;
        } catch (const EnglishLanguageException &e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
            std::cout << "Пожалуйста введите на русском и порпробуйте еще раз" << std::endl;
        }
    }

    std::cout << "Введите год рождения: ";
    std::cin >> year;
    clearInputBuffer();

    while (true) {
        std::cout << "Введите название факультета(Только русские символы): ";
        std::getline(std::cin, faculty);

        try {
            StringValidator::validateEnglishText(faculty);
            break;
        } catch (const EnglishLanguageException &e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
            std::cout << "Пожалуйста введите на русском и порпробуйте еще раз" << std::endl;
        }
    }

    auto *newStudent = new Student(name, year, faculty);

    std::cout << "Введите количество экзаменов: ";
    std::cin >> examCount;

    if (examCount > 0) {
        auto exams = new int[examCount];
        std::cout << "Введите результаты экзаменов: ";
        for (int i = 0; i < examCount; ++i) {
            std::cin >> exams[i];
        }
        clearInputBuffer();
        newStudent->setExamResults(exams, examCount);
        delete[] exams;
    }

    Student **oldStudents = studentsSpan.data();
    auto **newStudents = new Student *[studentCount + 1];

    for (int i = 0; i < studentCount; ++i) {
        newStudents[i] = oldStudents[i];
    }

    newStudents[studentCount] = newStudent;
    delete[] oldStudents;

    studentsSpan = std::span<Student *>(newStudents, studentCount + 1);
    studentCount++;

    std::cout << "Студент успешно добавлен!" << std::endl;

}


void displayStudents(std::span<Student *> studentsSpan) {
    if (studentsSpan.empty()) {
        std::cout << "Нет студентов." << std::endl;
    } else {
        for (const auto &student: studentsSpan) {
            student->display();
            std::cout << "-------------------" << std::endl;
        }
    }
}

void saveStudentsToFile(const std::string& filename, std::span<Student*> students) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл для записи!" << std::endl;
        return;
    }

    file << students.size() << std::endl;

    for (const auto& student : students) {
        student->saveToFile(file);
    }

    file.close();
    std::cout << "Студенты успешно сохранены в файл: " << filename << std::endl;
}

void loadStudentsFromFile(const std::string& filename, std::span<Student*>& studentsSpan, int& studentCount) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл для чтения!" << std::endl;
        return;
    }

    for (int i = 0; i < studentCount; ++i) {
        delete studentsSpan[i];
    }
    delete[] studentsSpan.data();

    std::string countStr;
    std::getline(file, countStr);
    int count = std::stoi(countStr);

    auto** newStudents = new Student*[count];

    for (int i = 0; i < count; ++i) {
        newStudents[i] = new Student();
        newStudents[i]->loadFromFile(file);
    }

    studentsSpan = std::span<Student*>(newStudents, count);
    studentCount = count;

    file.close();
    std::cout << "Студенты успешно загружены из файла: " << filename << std::endl;
}
void demonstrateFileIndexing(const std::string& filename) {
    StudentFile studentFile(filename);

    int studentCount = studentFile.getStudentCount();
    if (studentCount == 0) {
        std::cout << "Файл пуст. Сначала добавьте студентов и сохраните их." << std::endl;
        return;
    }

    std::cout << "=== Демонстрация доступа к студентам из файла через operator[] ===" << std::endl;
    std::cout << "Всего студентов в файле: " << studentCount << std::endl;

    for (int i = 0; i < studentCount; i++) {
        try {
            std::cout << "\n--- Студент #" << i << " из файла ---" << std::endl;
            Student student = studentFile[i];
            student.display();
        } catch (const std::invalid_argument& e) {
            std::cout << "Ошибка при доступе к студенту #" << i << ": " << e.what() << std::endl;
        }
    }

    std::cout << "\nДоступ к конкретному студенту по индексу" << std::endl;
    std::cout << "Введите индекс студента (0-" << studentCount - 1 << "): ";

    int index;
    std::cin >> index;
    clearInputBuffer();

    try {
        Student specificStudent = studentFile[index];
        std::cout << "\n--- Найденный студент ---" << std::endl;
        specificStudent.display();
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}