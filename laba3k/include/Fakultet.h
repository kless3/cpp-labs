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
    virtual ~Fakultet();

    Fakultet& operator=(const Fakultet& other);

    [[maybe_unused]] void setFacultyName(std::string_view name);

    [[maybe_unused]] [[nodiscard]]std::string getFacultyName() const;

    virtual void display() const;
};

#endif