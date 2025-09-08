#include "SmartArray.h"
#include <random>
#include <iostream>

SmartArray::SmartArray(int n) : size(n) {
    if (size > 0) {
        data = std::make_unique<std::unique_ptr<int>[]>(size);
        for (int i = 0; i < size; i++) {
            data[i] = std::make_unique<int>(0);
        }
    }
}

SmartArray::SmartArray(const SmartArray& other) : size(other.size) {
    if (size > 0) {
        data = std::make_unique<std::unique_ptr<int>[]>(size);
        for (int i = 0; i < size; i++) {
            data[i] = std::make_unique<int>(*other.data[i]);
        }
    }
}

SmartArray& SmartArray::operator=(const SmartArray& other) {
    if (this == &other) return *this;

    // Очищаем текущие данные
    data.reset();

    size = other.size;
    if (size > 0) {
        data = std::make_unique<std::unique_ptr<int>[]>(size);
        for (int i = 0; i < size; i++) {
            data[i] = std::make_unique<int>(*other.data[i]);
        }
    }
    return *this;
}

SmartArray::~SmartArray() {
    data.reset();
}

void SmartArray::fillManual() {
    for (int i = 0; i < size; i++) {
        std::cin >> *data[i];
    }
}

void SmartArray::fillRandom(int min, int max) {
    if (size <= 0) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < size; i++) {
        *data[i] = dist(gen);
    }
}

void SmartArray::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << *data[i] << " ";
    }
    std::cout << std::endl;
}

int SmartArray::getSize() const {
    return size;
}

int SmartArray::getElement(int index) const {
    if (index >= 0 && index < size) {
        return *data[index];
    }
    return 0;
}

void SmartArray::resize(int newSize) {
    if (newSize == size) return;

    if (newSize <= 0) {
        data.reset();
        size = 0;
        return;
    }

    auto newData = std::make_unique<std::unique_ptr<int>[]>(newSize);
    int limit = (newSize < size) ? newSize : size;

    // Копируем существующие элементы
    for (int i = 0; i < limit; i++) {
        newData[i] = std::move(data[i]);
    }

    // Инициализируем новые элементы
    for (int i = limit; i < newSize; i++) {
        newData[i] = std::make_unique<int>(0);
    }

    data = std::move(newData);
    size = newSize;
}

SmartArray SmartArray::intersection(const SmartArray& a, const SmartArray& b) {
    if (a.size == 0 || b.size == 0) return SmartArray(0);

    int maxSize = (a.size < b.size) ? a.size : b.size;
    auto temp = std::make_unique<std::unique_ptr<int>[]>(maxSize);
    int k = 0;

    for (int i = 0; i < a.size; i++) {
        int currentValue = *a.data[i];
        bool inB = false;

        for (int j = 0; j < b.size; j++) {
            if (currentValue == *b.data[j]) {
                inB = true;
                break;
            }
        }
        if (!inB) continue;

        bool exists = false;
        for (int x = 0; x < k; x++) {
            if (*temp[x] == currentValue) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            temp[k] = std::make_unique<int>(currentValue);
            k++;
        }
    }

    SmartArray result(k);
    for (int i = 0; i < k; i++) {
        *result.data[i] = *temp[i];
    }
    return result;
}

SmartArray SmartArray::unionArrays(const SmartArray& a, const SmartArray& b) {
    int maxSize = a.size + b.size;
    auto temp = std::make_unique<std::unique_ptr<int>[]>(maxSize);
    int k = 0;

    // Добавляем элементы из первого массива
    for (int i = 0; i < a.size; i++) {
        temp[k] = std::make_unique<int>(*a.data[i]);
        k++;
    }

    // Добавляем уникальные элементы из второго массива
    for (int i = 0; i < b.size; i++) {
        int currentValue = *b.data[i];
        bool exists = false;

        for (int j = 0; j < k; j++) {
            if (*temp[j] == currentValue) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            temp[k] = std::make_unique<int>(currentValue);
            k++;
        }
    }

    SmartArray result(k);
    for (int i = 0; i < k; i++) {
        *result.data[i] = *temp[i];
    }
    return result;
}