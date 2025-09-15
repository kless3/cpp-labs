#ifndef STUDENT_H
#define STUDENT_H

#include "Fakultet.h"
#include <string>

class Student : public Fakultet {
private:
    std::string fullName;
    int birthYear;
    int* examResults;
    int examsCount;

public:
    Student();
    Student(const std::string& name, int year, const std::string& faculty);
    Student(const Student& other);
    ~Student();

    Student& operator=(const Student& other);

    void setFullName(const std::string& name);
    void setBirthYear(int year);
    void setExamResults(const int* results, int count);

    std::string getFullName() const;
    int getBirthYear() const;
    const int* getExamResults() const;
    int getExamsCount() const;

    double calculateAverage() const;
    void display() const override;
};

#endif