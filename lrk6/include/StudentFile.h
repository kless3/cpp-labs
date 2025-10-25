#ifndef STUDENTFILE_H
#define STUDENTFILE_H

#include "Student.h"
#include <string>

class StudentFile {
private:
    std::string filename;

public:
    explicit StudentFile(std::string  filename);

    Student operator[](int index) const;

    [[nodiscard]] int getStudentCount() const;
};

#endif