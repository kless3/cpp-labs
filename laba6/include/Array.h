#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <string>

class SafeArray {
private:
    int* data;
    int size;

public:
    explicit SafeArray(int arraySize);
    ~SafeArray();

    SafeArray(const SafeArray& other);

    SafeArray& operator=(const SafeArray& other);

    [[maybe_unused]] SafeArray(SafeArray&& other) noexcept;

    SafeArray& operator=(SafeArray&& other) noexcept;

    int& operator[](int index);
    const int& operator[](int index) const;

    [[nodiscard]] int getSize() const;

private:
    void cleanup() noexcept;
    void swap(SafeArray& other) noexcept;
};

#endif