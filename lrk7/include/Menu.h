#ifndef MENU_H
#define MENU_H
#include "../include/FileIndexer.h"

void displayMenu();
void handleRead(FileIndexer& indexer);
void handleWrite(FileIndexer& indexer);

#endif