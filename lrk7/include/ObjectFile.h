#ifndef OBJECTFILE_H
#define OBJECTFILE_H

#include "Object.h"
#include <string>

class ObjectFile {
private:
    std::string filename;

public:
    explicit ObjectFile(std::string filename);
    Object* operator[](int index) const;
    int getObjectCount() const;
};

#endif