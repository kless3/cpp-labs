#include "../include/Array.h"
#include "../include/IndexOutOfBoundsException.h"



SafeArray::SafeArray(int arraySize) : size(arraySize) {
    if (arraySize <= 0) {
        throw std::invalid_argument("Array size must be positive");
    }
    data = new int[size];
}

SafeArray::~SafeArray() {
    delete[] data;
}

int& SafeArray::operator[](int index) {
    if (index < 0 || index >= size) {
        throw IndexOutOfBoundsException(index, size);
    }
    return data[index];
}

const int& SafeArray::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw IndexOutOfBoundsException(index, size);
    }
    return data[index];
}

int SafeArray::getSize() const {
    return size;
}