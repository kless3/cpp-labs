#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <string_view>
#include <fstream>

class Object {
public:
    virtual ~Object() = default;
    virtual void display() const = 0;
    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(std::ifstream& file) = 0;
    virtual std::string getType() const = 0;
};

#endif