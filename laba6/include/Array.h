#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <string>

class IndexOutOfBoundsException : public std::out_of_range {
public:
    explicit IndexOutOfBoundsException([[maybe_unused]] int index, [[maybe_unused]] int size);

    [[nodiscard]] static std::string createMessage(int index, int size) ;
};

class SafeArray {
private:
    int* data;
    int size;

public:
    explicit SafeArray(int arraySize);
    ~SafeArray();

    SafeArray(const SafeArray&) = delete;
    SafeArray& operator=(const SafeArray&) = delete;

    [[maybe_unused]] SafeArray(SafeArray&& other) noexcept;
    SafeArray& operator=(SafeArray&& other) noexcept;

    int& operator[](int index);
    const int& operator[](int index) const;

    [[nodiscard]] int getSize() const;
};

#endif