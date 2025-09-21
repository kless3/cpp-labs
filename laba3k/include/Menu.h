
#ifndef LABA3_MENU_H
#define LABA3_MENU_H

#include "../include/Student.h"
#include <iostream>
#include <limits>
#include <span>

void displayMenu();
void clearInputBuffer();
void addStudent(std::span<Student>& students, int& studentCount);
void displayStudents(std::span<Student> students);


#endif
