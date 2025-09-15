#ifndef FAKULTET_H
#define FAKULTET_H

#include <string>
#include <string_view>

class Fakultet {
private:
    std::string facultyName;

public:
    Fakultet();
    explicit Fakultet(std::string_view name);
    Fakultet(const Fakultet& other);
    virtual ~Fakultet() = default;

    Fakultet& operator=(const Fakultet& other);

    void setFacultyName(std::string_view name);
    std::string getFacultyName() const;

    virtual void display() const;
};

#endif