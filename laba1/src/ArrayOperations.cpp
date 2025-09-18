#include "../include/ArrayOperations.h"
#include <iostream>
#include <algorithm>
#include <utility>

ArrayOperations::ArrayOperations(int* arr, int n) {
    size = n;
    array = new int[size];
    for (auto i = 0; i < size; i++) {
        array[i] = arr[i];
    }
}

ArrayOperations::~ArrayOperations() {
    delete[] array;
}

ArrayOperations::ArrayOperations(const ArrayOperations& other) {
    size = other.size;
    array = new int[size];
    for (auto i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
}

ArrayOperations::ArrayOperations(ArrayOperations&& other) noexcept {
    size = other.size;
    array = other.array;
    other.size = 0;
    other.array = nullptr;
}

bool elementExistsInTemp(const int* temp, int count, int value) {
    for (auto k = 0; k < count; k++) {
        if (temp[k] == value) {
            return true;
        }
    }
    return false;
}

bool elementExistsInArray(const int* array, int size, int value) {
    for (auto j = 0; j < size; j++) {
        if (array[j] == value) {
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

        if (!elementExistsInArray(arr2.array, arr2.size, currentElement)) {
            continue;
        }

        if (elementExistsInTemp(temp, count, currentElement)) {
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

        if (!elementExistsInTemp(temp, count, currentElement)) {
            temp[count++] = currentElement;
        }
    }

    for (auto i = 0; i < arr2.size; i++) {
        auto currentElement = arr2.array[i];

        if (!elementExistsInTemp(temp, count, currentElement)) {
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

int* ArrayOperations::getArray() const {
    return array;
}