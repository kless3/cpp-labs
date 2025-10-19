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
    bool openFileForWrite();
    void closeFile();
    std::string operator[](long wordIndex);
    bool writeWord(const std::string& word);
    bool writeWords(const std::string& words);
    bool appendWord(const std::string& word);
    long getWordCount() const;
};

#endif