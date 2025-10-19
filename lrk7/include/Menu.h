#ifndef MENU_H
#define MENU_H

#include "../include/FileIndexer.h"
#include <string>

// Функции меню
void printMenu();
bool handleOpenFile(FileIndexer& indexer, const std::string& filename);
bool handleGetWord(FileIndexer& indexer);
bool handleShowWordCount(FileIndexer& indexer);
bool handleWriteWord(FileIndexer& indexer);
bool handleChoice(FileIndexer& indexer, const std::string& filename, int choice);

#endif