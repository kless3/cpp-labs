#ifndef UTILS_H
#define UTILS_H

#include "Person.h"
#include "Girl.h"
#include "YoungMan.h"

void showAllReactions(Person** people, int count);
void addGirl(Person*** people, int* count, int* capacity);
void addYoungMan(Person*** people, int* count, int* capacity);

#endif