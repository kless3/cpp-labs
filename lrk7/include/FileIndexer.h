#ifndef FILEINDEXER_H
#define FILEINDEXER_H

#include <string>

class FileIndexer {
private:
    std::string filename;
    FILE* file;
    long fileSize;
    long wordCount;

    bool isWhitespace(char c);
    long calculateWordCount();
    long findWordPosition(long wordIndex);

public:
    FileIndexer(const std::string& filename);
    ~FileIndexer();

    bool openFile();
    void closeFile();
    std::string operator[](long wordIndex);
    long getWordCount() const;
};

#endif