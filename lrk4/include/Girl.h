#ifndef GIRL_H
#define GIRL_H

#include "person.h"

class Girl : public Person {
public:
    Girl(const std::string& n);
    void reactToNewPerson(const Person* other) const override;
};

#endif