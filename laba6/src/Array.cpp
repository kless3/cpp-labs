#include "../include/Array.h"
#include <sstream>

std::string IndexOutOfBoundsException::createMessage(int index, int size) {
    std::ostringstream message;
    message << "Index " << index << " is out of bounds for array of size " << size;
    return message.str();
}

IndexOutOfBoundsException::IndexOutOfBoundsException([[maybe_unused]] int index, [[maybe_unused]] int size)
        : std::out_of_range(createMessage(index, size)) {}



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

[[maybe_unused]] SafeArray::SafeArray(SafeArray&& other) noexcept
        : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

SafeArray& SafeArray::operator=(SafeArray&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}