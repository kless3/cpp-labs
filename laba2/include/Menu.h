#ifndef MENU_H
#define MENU_H

#include "../include/String.h"

void clearInputBuffer();

void displayMenu();

void handleMenuChoice(int choice, String &currentString);

void handleInputString(String &currentString);

void handleCheckEmpty(const String &currentString);

void handleGetSubstring(String &currentString);

void handleGetChar(const String &currentString);

void handleChangeChar(String &currentString);

void handleShowString(const String &currentString);

#endif