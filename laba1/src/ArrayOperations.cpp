#include "../include/ArrayOperations.h"
#include <iostream>
#include <algorithm>
#include <utility>

ArrayOperations::ArrayOperations(const int* arr, int n)
        : size(n), array(new int[n]) {
    for (auto i = 0; i < size; i++) {
        array[i] = arr[i];
    }
}

ArrayOperations::~ArrayOperations() {
    delete[] array;
}

ArrayOperations::ArrayOperations(const ArrayOperations& other)
        : size(other.size), array(new int[other.size]) {
    for (auto i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
}

ArrayOperations::ArrayOperations(ArrayOperations&& other) noexcept
        : size(other.size), array(other.array) {
    other.size = 0;
    other.array = nullptr;
}

bool ArrayOperations::elementExists(const ArrayOperations& arr, int value) {
    for (auto i = 0; i < arr.size; i++) {
        if (arr.array[i] == value) {
            return true;
        }
    }
    return false;
}

ArrayOperations ArrayOperations::intersection(const ArrayOperations& arr1, const ArrayOperations& arr2) {
    auto maxSize = std::min(arr1.size, arr2.size);
    auto temp = new int[maxSize];
    auto count = 0;

    for (auto i = 0; i < arr1.size; i++) {
        auto currentElement = arr1.array[i];

        if (!elementExists(arr2, currentElement)) {
            continue;
        }

        if (elementExists(ArrayOperations(temp, count), currentElement)) {
            continue;
        }

        temp[count++] = currentElement;
    }

    ArrayOperations result(temp, count);
    delete[] temp;
    return result;
}

ArrayOperations ArrayOperations::unionArrays(const ArrayOperations& arr1, const ArrayOperations& arr2) {
    auto maxSize = arr1.size + arr2.size;
    auto temp = new int[maxSize];
    auto count = 0;

    for (auto i = 0; i < arr1.size; i++) {
        auto currentElement = arr1.array[i];

        if (!elementExists(ArrayOperations(temp, count), currentElement)) {
            temp[count++] = currentElement;
        }
    }

    for (auto i = 0; i < arr2.size; i++) {
        auto currentElement = arr2.array[i];

        if (!elementExists(ArrayOperations(temp, count), currentElement)) {
            temp[count++] = currentElement;
        }
    }

    ArrayOperations result(temp, count);
    delete[] temp;
    return result;
}

void ArrayOperations::display() const {
    for (auto i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int ArrayOperations::getSize() const {
    return size;
}

const int* ArrayOperations::getArray() const {
    return array;
}