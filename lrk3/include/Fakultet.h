#ifndef FAKULTET_H
#define FAKULTET_H

#include <string>

class Fakultet {
protected:
    std::string facultyName;

public:
    Fakultet();
    Fakultet(const std::string& name);
    Fakultet(const Fakultet& other);
    virtual ~Fakultet();

    Fakultet& operator=(const Fakultet& other);

    void setFacultyName(const std::string& name);
    std::string getFacultyName() const;

    virtual void display() const;
};

#endif