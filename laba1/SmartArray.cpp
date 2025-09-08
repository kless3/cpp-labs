#include "SmartArray.h"
#include <cstdlib>

SmartArray::SmartArray(int n) : size(n) {
    data = (size > 0) ? new int[size] : nullptr;
}

SmartArray::SmartArray(const SmartArray& other) : size(other.size) {
    data = (size > 0) ? new int[size] : nullptr;
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

SmartArray::~SmartArray() {
    delete[] data;
}

SmartArray& SmartArray::operator=(const SmartArray& other) {
    if (this == &other) return *this;

    delete[] data;
    size = other.size;
    data = (size > 0) ? new int[size] : nullptr;
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];

    return *this;
}

void SmartArray::fillManual() {
    for (int i = 0; i < size; i++) {
        std::cout << "Введите элемент [" << i << "]: ";
        std::cin >> data[i];
    }
}

void SmartArray::fillRandom(int min, int max) {
    for (int i = 0; i < size; i++) {
        data[i] = min + rand() % (max - min + 1);
    }
}

void SmartArray::print() const {
    for (int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

int SmartArray::getSize() const {
    return size;
}

int SmartArray::getElement(int index) const {
    return (index >= 0 && index < size) ? data[index] : 0;
}

void SmartArray::resize(int newSize) {
    if (newSize == size) return;

    int* newData = (newSize > 0) ? new int[newSize] : nullptr;

    int limit = (newSize < size) ? newSize : size;
    for (int i = 0; i < limit; i++)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    size = newSize;
}

SmartArray SmartArray::intersection(const SmartArray& a, const SmartArray& b) {
    if (a.size == 0 || b.size == 0) return SmartArray(0);

    int* temp = new int[(a.size < b.size) ? a.size : b.size];
    int k = 0;

    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < b.size; j++) {
            if (a.data[i] == b.data[j]) {
                bool exists = false;
                for (int x = 0; x < k; x++) {
                    if (temp[x] == a.data[i]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) temp[k++] = a.data[i];
            }
        }
    }

    SmartArray result(k);
    for (int i = 0; i < k; i++)
        result.data[i] = temp[i];

    delete[] temp;
    return result;
}

SmartArray SmartArray::unionArrays(const SmartArray& a, const SmartArray& b) {
    int maxSize = a.size + b.size;
    int* temp = new int[maxSize];
    int k = 0;

    for (int i = 0; i < a.size; i++)
        temp[k++] = a.data[i];

    for (int i = 0; i < b.size; i++) {
        bool exists = false;
        for (int j = 0; j < k; j++) {
            if (temp[j] == b.data[i]) {
                exists = true;
                break;
            }
        }
        if (!exists)
            temp[k++] = b.data[i];
    }

    SmartArray result(k);
    for (int i = 0; i < k; i++)
        result.data[i] = temp[i];

    delete[] temp;
    return result;
}
