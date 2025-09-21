#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <memory>
#include "../include/Person.h"
#include "../include/Girl.h"
#include "../include/YoungMan.h"

void showAllReactions(const std::vector<std::unique_ptr<Person>>& people);

void addGirl(std::vector<std::unique_ptr<Person>>& people);

void addYoungMan(std::vector<std::unique_ptr<Person>>& people);

void handleMenuChoice(int choice, std::vector<std::unique_ptr<Person>>& people);

#endif
