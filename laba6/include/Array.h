#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <string>

class IndexOutOfBoundsException : public std::out_of_range {
public:
    explicit IndexOutOfBoundsException(int index, int size);

    static std::string createMessage(int index, int size);
};

class SafeArray {
private:
    int* data;
    int size;

public:
    explicit SafeArray(int arraySize);
    ~SafeArray();

    int& operator[](int index);
    const int& operator[](int index) const;

    [[nodiscard]] int getSize() const;
};

#endif