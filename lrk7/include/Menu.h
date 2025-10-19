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
    explicit Menu(const std::string& filename);
    ~Menu();

    // Delete copy operations
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;

    // Default move operations
    Menu(Menu&&) = default;
    Menu& operator=(Menu&&) = default;

    void printMenu();
    bool handleChoice(int choice);
};

#endif