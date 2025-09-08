#ifndef LABA1_SMARTARRAY_H
#define LABA1_SMARTARRAY_H

#include <iostream>

class SmartArray {
private:
    int* data;
    int size;

public:

    SmartArray(int n = 0);

    SmartArray(const SmartArray& other);

    ~SmartArray();

    SmartArray& operator=(const SmartArray& other);

    void fillManual();
    void fillRandom(int min = 0, int max = 100);

    void print() const;

    int getSize() const;
    int getElement(int index) const;

    void resize(int newSize);

    static SmartArray intersection(const SmartArray& a, const SmartArray& b);
    static SmartArray unionArrays(const SmartArray& a, const SmartArray& b);
};

#endif //LABA1_SMARTARRAY_H
