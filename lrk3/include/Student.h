#ifndef STUDENT_H
#define STUDENT_H

#include "Fakultet.h"
#include <string>
#include <string_view>

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
    ~Student();

    Student& operator=(const Student& other);

    void setFullName(std::string_view name);
    void setBirthYear(int year);
    void setExamResults(const int* results, int count);

    std::string getFullName() const;
    int getBirthYear() const;
    const int* getExamResults() const;
    int getExamsCount() const;

    double calculateAverage() const;
    void display() const final;
};

#endif