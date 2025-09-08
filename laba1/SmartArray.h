#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <iostream>
#include <memory>

class SmartArray {
private:
    std::unique_ptr<int[]> data;
    int size{0};

    SmartArray(int n, std::unique_ptr<int[]> arr);

public:
    explicit SmartArray(int n = 0);
    SmartArray(const SmartArray& other);
    SmartArray& operator=(const SmartArray& other);
    ~SmartArray();

    void print() const;
    int getSize() const;
    int getElement(int index) const;

    SmartArray resize(int newSize) const;
    static SmartArray intersection(const SmartArray& a, const SmartArray& b);
    static SmartArray unionArrays(const SmartArray& a, const SmartArray& b);

    static SmartArray fillManual(int n);
    static SmartArray fillRandom(int n, int min = 0, int max = 100);
};

#endif
