#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;
public:
    explicit Person(std::string  n);
    virtual ~Person() = default;
    virtual void reactToNewPerson(const Person* other) const = 0;
    [[nodiscard]] std::string getName() const;
};

#endif