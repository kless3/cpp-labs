#ifndef FILEINDEXER_H
#define FILEINDEXER_H

#include <fstream>

class FileIndexer {
private:
    std::fstream file;
    int elementSize;
    long fileSize;

public:
    FileIndexer(int elemSize);
    bool openFile();
    void* operator[](long index);
    void writeElement(long index, void* data);
};

#endif