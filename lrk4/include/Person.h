#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;
public:
    explicit Person(const std::string& n);
    virtual ~Person() = default;
    virtual void reactToNewPerson(const Person* other) const = 0;
    std::string getName() const;
};

#endif