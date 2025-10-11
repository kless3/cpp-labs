#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <string>

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