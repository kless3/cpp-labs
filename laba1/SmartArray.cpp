#include "SmartArray.h"
#include <random>
#include <iostream>

SmartArray::SmartArray(int n) : size(n) {
    if (size > 0) data = std::make_unique<int[]>(size);
}

SmartArray::SmartArray(int n, std::unique_ptr<int[]> arr) : size(n), data(std::move(arr)) {}

SmartArray::SmartArray(const SmartArray& other) : size(other.size) {
    if (size > 0) {
        data = std::make_unique<int[]>(size);
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }
}

SmartArray& SmartArray::operator=(const SmartArray& other) {
    if (this == &other) return *this;
    size = other.size;
    if (size > 0) {
        data = std::make_unique<int[]>(size);
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    } else {
        data.reset();
    }
    return *this;
}

SmartArray::~SmartArray() {
    data.reset();
}

void SmartArray::print() const {
    for (int i = 0; i < size; i++) std::cout << data[i] << " ";
    std::cout << std::endl;
}

int SmartArray::getSize() const { return size; }

int SmartArray::getElement(int index) const {
    if (index >= 0 && index < size) return data[index];
    return 0;
}

SmartArray SmartArray::resize(int newSize) const {
    auto newData = (newSize > 0) ? std::make_unique<int[]>(newSize) : nullptr;
    int limit = (newSize < size) ? newSize : size;
    for (int i = 0; i < limit; i++) newData[i] = data[i];
    return SmartArray(newSize, std::move(newData));
}

SmartArray SmartArray::fillManual(int n) {
    auto arr = std::make_unique<int[]>(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    return SmartArray(n, std::move(arr));
}

SmartArray SmartArray::fillRandom(int n, int min, int max) {
    auto arr = std::make_unique<int[]>(n);
    for (int i = 0; i < n; i++) {
        auto r = static_cast<int>(min + (std::random_device{}() % (max - min + 1)));
        arr[i] = r;
    }
    return SmartArray(n, std::move(arr));
}

SmartArray SmartArray::intersection(const SmartArray& a, const SmartArray& b) {
    if (a.size == 0 || b.size == 0) return SmartArray(0);

    int maxSize = (a.size < b.size) ? a.size : b.size;
    auto temp = std::make_unique<int[]>(maxSize);
    int k = 0;

    for (int i = 0; i < a.size; i++) {
        bool inB = false;
        for (int j = 0; j < b.size; j++) {
            if (a.data[i] == b.data[j]) {
                inB = true;
                break;
            }
        }
        if (!inB) continue;

        bool exists = false;
        for (int x = 0; x < k; x++) {
            if (temp[x] == a.data[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            temp[k] = a.data[i];
            k++;
        }
    }

    auto resultData = std::make_unique<int[]>(k);
    for (int i = 0; i < k; i++) resultData[i] = temp[i];
    return SmartArray(k, std::move(resultData));
}

SmartArray SmartArray::unionArrays(const SmartArray& a, const SmartArray& b) {
    int maxSize = a.size + b.size;
    auto temp = std::make_unique<int[]>(maxSize);
    int k = 0;

    for (int i = 0; i < a.size; i++) temp[k++] = a.data[i];

    for (int i = 0; i < b.size; i++) {
        bool exists = false;
        for (int j = 0; j < k; j++) {
            if (temp[j] == b.data[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) temp[k++] = b.data[i];
    }

    auto resultData = std::make_unique<int[]>(k);
    for (int i = 0; i < k; i++) resultData[i] = temp[i];
    return SmartArray(k, std::move(resultData));
}
