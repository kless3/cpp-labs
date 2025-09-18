#ifndef ARRAYOPERATIONS_H
#define ARRAYOPERATIONS_H

class ArrayOperations {
private:
    int* array;
    int size;

public:
    ArrayOperations(int* arr, int n);
    ~ArrayOperations();

    static ArrayOperations intersection(const ArrayOperations& arr1, const ArrayOperations& arr2);
    static ArrayOperations unionArrays(const ArrayOperations& arr1, const ArrayOperations& arr2);

    void display() const;
    int getSize() const;
    int* getArray() const;
};

#endif