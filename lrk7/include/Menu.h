#ifndef MENU_H
#define MENU_H

#include "../include/FileIndexer.h"

class Menu {
private:
    FileIndexer* indexer;
    std::string filename;

    void handleOpenFile();
    void handleGetWord();
    void handleShowWordCount();
    void handleWriteWord();

public:
    Menu(const std::string& filename);
    ~Menu();

    void printMenu();
    bool handleChoice(int choice);
};

#endif