#include "../include/Menu.h"
#include "../include/StringValidator.h"
#include "../include/EnglishLanguageException.h"
#include <iostream>
#include <limits>
#include <span>

void displayMenu() {
    std::cout << "1. �������� ��������" << std::endl;
    std::cout << "2. �������� ���� ���������" << std::endl;
    std::cout << "3. ��������� ��������� � ����" << std::endl;
    std::cout << "4. ��������� ��������� �� �����" << std::endl;
    std::cout << "5. ������ � ��������� �� ����� ����� operator[]" << std::endl;
    std::cout << "6. �����" << std::endl;
    std::cout << "�������� ��������: ";
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
        std::cout << "������� ��� ��������(������ ������� �������): ";
        std::getline(std::cin, name);

        try {
            StringValidator::validateEnglishText(name);
            break;
        } catch (const EnglishLanguageException &e) {
            std::cout << "������: " << e.what() << std::endl;
            std::cout << "���������� ������� �� ������� � ����������� ��� ���" << std::endl;
        }
    }

    std::cout << "������� ��� ��������: ";
    std::cin >> year;
    clearInputBuffer();

    while (true) {
        std::cout << "������� �������� ����������(������ ������� �������): ";
        std::getline(std::cin, faculty);

        try {
            StringValidator::validateEnglishText(faculty);
            break;
        } catch (const EnglishLanguageException &e) {
            std::cout << "������: " << e.what() << std::endl;
            std::cout << "���������� ������� �� ������� � ����������� ��� ���" << std::endl;
        }
    }

    auto *newStudent = new Student(name, year, faculty);

    std::cout << "������� ���������� ���������: ";
    std::cin >> examCount;

    if (examCount > 0) {
        auto exams = new int[examCount];
        std::cout << "������� ���������� ���������: ";
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

    std::cout << "������� ������� ��������!" << std::endl;

}


void displayStudents(std::span<Student *> studentsSpan) {
    if (studentsSpan.empty()) {
        std::cout << "��� ���������." << std::endl;
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
        std::cout << "������: �� ������� ������� ���� ��� ������!" << std::endl;
        return;
    }

    file << students.size() << std::endl;

    for (const auto& student : students) {
        student->saveToFile(file);
    }

    file.close();
    std::cout << "�������� ������� ��������� � ����: " << filename << std::endl;
}

void loadStudentsFromFile(const std::string& filename, std::span<Student*>& studentsSpan, int& studentCount) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "������: �� ������� ������� ���� ��� ������!" << std::endl;
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
    std::cout << "�������� ������� ��������� �� �����: " << filename << std::endl;
}
void demonstrateFileIndexing(const std::string& filename) {
    StudentFile studentFile(filename);

    int studentCount = studentFile.getStudentCount();
    if (studentCount == 0) {
        std::cout << "���� ����. ������� �������� ��������� � ��������� ��." << std::endl;
        return;
    }

    std::cout << "=== ������������ ������� � ��������� �� ����� ����� operator[] ===" << std::endl;
    std::cout << "����� ��������� � �����: " << studentCount << std::endl;

    for (int i = 0; i < studentCount; i++) {
        try {
            std::cout << "\n--- ������� #" << i << " �� ����� ---" << std::endl;
            Student student = studentFile[i];
            student.display();
        } catch (const std::invalid_argument& e) {
            std::cout << "������ ��� ������� � �������� #" << i << ": " << e.what() << std::endl;
        }
    }

    std::cout << "\n������ � ����������� �������� �� �������" << std::endl;
    std::cout << "������� ������ �������� (0-" << studentCount - 1 << "): ";

    int index;
    std::cin >> index;
    clearInputBuffer();

    try {
        Student specificStudent = studentFile[index];
        std::cout << "\n--- ��������� ������� ---" << std::endl;
        specificStudent.display();
    } catch (const std::invalid_argument& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}