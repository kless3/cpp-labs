#ifndef YOUNGMAN_H
#define YOUNGMAN_H

#include "Person.h"

class YoungMan : public Person {
public:
    explicit YoungMan(const std::string& n);
    void reactToNewPerson(const Person* other) const override;
};

#endif