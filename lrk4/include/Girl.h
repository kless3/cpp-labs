#ifndef GIRL_H
#define GIRL_H

#include "Person.h"

class Girl : public Person {
public:
    explicit Girl(const std::string& n);
    void reactToNewPerson(const Person* other) const override;
};

#endif