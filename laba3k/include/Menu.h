
#ifndef LABA3_MENU_H
#define LABA3_MENU_H

#include "../include/Student.h"
#include <iostream>
#include <limits>

void displayMenu();
void clearInputBuffer();
void addStudent(Student *&students, int &studentCount);
void displayStudents(const Student *students, int studentCount);


#endif
