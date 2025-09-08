#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <iostream>
#include <memory>

class SmartArray {
private:
    std::unique_ptr<int[]> data;
    int size{0};

public:
    explicit SmartArray(int n = 0);
    SmartArray(const SmartArray& other);
    SmartArray& operator=(const SmartArray& other);
    ~SmartArray(); // Оставляем деструктор

    void fillManual();
    void fillRandom(int min = 0, int max = 100);
    void print() const;

    int getSize() const;
    int getElement(int index) const;

    void resize(int newSize);

    static SmartArray intersection(const SmartArray& a, const SmartArray& b);
    static SmartArray unionArrays(const SmartArray& a, const SmartArray& b);
};

#endif