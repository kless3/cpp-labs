#include "../include/ArrayOperations.h"
#include <iostream>
#include <algorithm>

ArrayOperations::ArrayOperations(int* arr, int n) {
    size = n;
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = arr[i];
    }
}

ArrayOperations::~ArrayOperations() {
    delete[] array;
}

ArrayOperations ArrayOperations::intersection(const ArrayOperations& arr1, const ArrayOperations& arr2) {
    int maxSize = std::min(arr1.size, arr2.size);
    int* temp = new int[maxSize];
    int count = 0;

    for (int i = 0; i < arr1.size; i++) {
        for (int j = 0; j < arr2.size; j++) {
            if (arr1.array[i] == arr2.array[j]) {
                bool exists = false;
                for (int k = 0; k < count; k++) {
                    if (temp[k] == arr1.array[i]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    temp[count++] = arr1.array[i];
                }
                break;
            }
        }
    }

    ArrayOperations result(temp, count);
    delete[] temp;
    return result;
}

ArrayOperations ArrayOperations::unionArrays(const ArrayOperations& arr1, const ArrayOperations& arr2) {
    int maxSize = arr1.size + arr2.size;
    int* temp = new int[maxSize];
    int count = 0;

    for (int i = 0; i < arr1.size; i++) {
        bool exists = false;
        for (int j = 0; j < count; j++) {
            if (temp[j] == arr1.array[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            temp[count++] = arr1.array[i];
        }
    }

    for (int i = 0; i < arr2.size; i++) {
        bool exists = false;
        for (int j = 0; j < count; j++) {
            if (temp[j] == arr2.array[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            temp[count++] = arr2.array[i];
        }
    }

    ArrayOperations result(temp, count);
    delete[] temp;
    return result;
}

void ArrayOperations::display() const {
    for (int i = 0; i < size; i++) {
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