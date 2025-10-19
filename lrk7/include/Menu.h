#ifndef MENU_H
#define MENU_H

#include "FileIndexer.h"

class Menu {
private:
    FileIndexer* indexer = nullptr;
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

    // Custom move operations
    Menu(Menu&& other) noexcept;
    Menu& operator=(Menu&& other) noexcept;

    void printMenu();
    bool handleChoice(int choice);
};

#endif