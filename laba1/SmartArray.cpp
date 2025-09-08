#include "SmartArray.h"
#include <random>

SmartArray::SmartArray(int n) : size(n) {
    if (size > 0) data = std::make_unique<int[]>(size);
}

SmartArray::SmartArray(const SmartArray& other) : size(other.size) {
    if (size > 0) {
        data = std::make_unique<int[]>(size);
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }
}

SmartArray::~SmartArray() {
    data.reset();
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

void SmartArray::fillManual() {
    for (int i = 0; i < size; i++) std::cin >> data[i];
}

void SmartArray::fillRandom(int min, int max) {
    if (size <= 0) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < size; i++) {
        data[i] = dist(gen);
    }
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

void SmartArray::resize(int newSize) {
    if (newSize == size) return;
    auto newData = (newSize > 0) ? std::make_unique<int[]>(newSize) : nullptr;
    int limit = (newSize < size) ? newSize : size;
    for (int i = 0; i < limit; i++) newData[i] = data[i];
    data = std::move(newData);
    size = newSize;
}

SmartArray SmartArray::intersection(const SmartArray& a, const SmartArray& b) {
    if (a.size == 0 || b.size == 0) return SmartArray(0);

    int maxSize = (a.size < b.size) ? a.size : b.size;
    auto temp = std::make_unique<int[]>(maxSize);
    int k = 0;

    for (int i = 0; i < a.size; i++) {
        bool inB = false;
        for (int j = 0; j < b.size; j++) {
            if (a.data[j] == a.data[i]) {
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

    SmartArray result(k);
    for (int i = 0; i < k; i++) result.data[i] = temp[i];
    return result;
}

SmartArray SmartArray::unionArrays(const SmartArray& a, const SmartArray& b) {
    int maxSize = a.size + b.size;
    auto temp = std::make_unique<int[]>(maxSize);
    int k = 0;

    for (int i = 0; i < a.size; i++) {
        temp[k] = a.data[i];
        k++;
    }

    for (int i = 0; i < b.size; i++) {
        bool exists = false;
        for (int j = 0; j < k; j++) {
            if (temp[j] == b.data[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            temp[k] = b.data[i];
            k++;
        }
    }

    SmartArray result(k);
    for (int i = 0; i < k; i++) result.data[i] = temp[i];
    return result;
}

