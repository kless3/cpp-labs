#ifndef MENU_H
#define MENU_H

#include "Object.h"
#include "ObjectFile.h"
#include <iostream>
#include <limits>
#include <span>

void displayMenu();
void clearInputBuffer();
void addObject(std::span<Object*>& objects, int& objectCount);
void displayObjects(std::span<Object*> objects);
void saveObjectsToFile(const std::string& filename, std::span<Object*> objects);
void loadObjectsFromFile(const std::string& filename, std::span<Object*>& objects, int& objectCount);
void demonstrateFileIndexing(const std::string& filename);

#endif