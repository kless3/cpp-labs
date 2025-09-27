#include "../include/FileIndexer.h"
#include <iostream>

FileIndexer::FileIndexer(int elemSize) : elementSize(elemSize) {
    file.open("data.txt", std::ios::binary | std::ios::in | std::ios::out);
    if (!file.is_open()) {
        file.open("data.txt", std::ios::binary | std::ios::out);
        file.close();
        file.open("data.txt", std::ios::binary | std::ios::in | std::ios::out);
    }
    file.seekg(0, std::ios::end);
    fileSize = file.tellg() / elementSize;
    file.seekg(0, std::ios::beg);
}

bool FileIndexer::openFile() {
    return file.is_open();
}

void* FileIndexer::operator[](long index) {
    static char buffer[256];

    file.seekg(index * elementSize, std::ios::beg);
    file.read(buffer, elementSize);

    if (file.fail()) {
        std::cout << "Read error" << std::endl;
        return nullptr;
    }

    return buffer;
}

void FileIndexer::writeElement(long index, void* data) {
    file.seekp(index * elementSize, std::ios::beg);
    file.write((char*)data, elementSize);
    file.flush();
}