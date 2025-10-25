#ifndef LABA3_MENU_H
#define LABA3_MENU_H

#include "../include/Student.h"
#include "../include/StudentFile.h"
#include <iostream>
#include <limits>
#include <span>

void displayMenu();
void clearInputBuffer();
void addStudent(std::span<Student*>& students, int& studentCount);
void displayStudents(std::span<Student*> students);
void saveStudentsToFile(const std::string& filename, std::span<Student*> students);
void loadStudentsFromFile(const std::string& filename, std::span<Student*>& students, int& studentCount);
void demonstrateFileIndexing(const std::string& filename);

#endif