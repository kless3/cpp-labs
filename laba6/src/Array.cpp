#include "../include/Array.h"
#include "../include/IndexOutOfBoundsException.h"
#include <utility>

SafeArray::SafeArray(int arraySize) : size(arraySize) {
    if (arraySize <= 0) {
        throw std::invalid_argument("Array size must be positive");
    }
    data = new int[size]();
}

SafeArray::~SafeArray() {
    cleanup();
}

void SafeArray::cleanup() noexcept {
    delete[] data;
    data = nullptr;
    size = 0;
}

void SafeArray::swap(SafeArray& other) noexcept {
    using std::swap;
    swap(data, other.data);
    swap(size, other.size);
}

SafeArray::SafeArray(const SafeArray& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

SafeArray& SafeArray::operator=(const SafeArray& other) {
    if (this != &other) {
        SafeArray temp(other);
        swap(temp);
    }
    return *this;
}

[[maybe_unused]] SafeArray::SafeArray(SafeArray&& other) noexcept
        : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

SafeArray& SafeArray::operator=(SafeArray&& other) noexcept {
    if (this != &other) {
        cleanup();
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
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