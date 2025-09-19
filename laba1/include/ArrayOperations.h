#ifndef ARRAYOPERATIONS_H
#define ARRAYOPERATIONS_H

class ArrayOperations {
private:
    int size;
    int* array;

public:
    ArrayOperations(const int* arr, int n);
    ~ArrayOperations();

    ArrayOperations(const ArrayOperations& other);
    ArrayOperations& operator=(const ArrayOperations& other) = delete;
    ArrayOperations(ArrayOperations&& other) noexcept;
    ArrayOperations& operator=(ArrayOperations&& other) noexcept = delete;

    static bool elementExistsInArray(const ArrayOperations& arr, int value);

    static ArrayOperations intersection(const ArrayOperations& arr1, const ArrayOperations& arr2);
    static ArrayOperations unionArrays(const ArrayOperations& arr1, const ArrayOperations& arr2);

    void display() const;
    int getSize() const;
    const int* getArray() const;

    bool elementExistsInArray(const ArrayOperations &arr, int value);
};

#endif