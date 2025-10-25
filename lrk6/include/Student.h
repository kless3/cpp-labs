#ifndef STUDENT_H
#define STUDENT_H

#include "Fakultet.h"
#include <string>
#include <string_view>
#include <fstream>

class Student : public Fakultet {
private:
    std::string fullName;
    int birthYear;
    int* examResults;
    int examsCount = 0;

public:
    Student();
    Student(std::string_view name, int year, std::string_view faculty);
    Student(const Student& other);
    ~Student() override;

    Student& operator=(const Student& other);

    [[maybe_unused]] void setFullName(std::string_view name);
    [[maybe_unused]] void setBirthYear(int year);
    void setExamResults(const int* results, int count);

    [[maybe_unused]] [[nodiscard]] std::string getFullName() const;
    [[maybe_unused]] [[nodiscard]] int getBirthYear() const;
    [[maybe_unused]] [[nodiscard]] const int* getExamResults() const;
    [[maybe_unused]] [[nodiscard]] int getExamsCount() const;

    [[nodiscard]] double calculateAverage() const;
    void display() const final;

    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);
};

#endif