#ifndef YOUNGMAN_H
#define YOUNGMAN_H

#include "person.h"

class YoungMan : public Person {
public:
    YoungMan(const std::string& n);
    void reactToNewPerson(const Person* other) const override;
};

#endif