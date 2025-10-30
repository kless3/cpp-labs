#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"
#include "Iterator.h"
#include <iostream>

template <typename T>
class Deque {
private:
    Node<T>* front = nullptr;
    Node<T>* rear = nullptr;
    int size = 0;

    void copyFrom(const Deque& other);

public:
    Deque();
    ~Deque() noexcept;

    Deque(const Deque& other);
    Deque& operator=(const Deque& other);
    Deque(Deque&& other) noexcept;
    Deque& operator=(Deque&& other) noexcept;

    void enqueueFront(const T& value);
    void enqueueRear(const T& value);
    T dequeueFront() noexcept;
    T dequeueRear() noexcept;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int getSize() const;
    void clear() noexcept;
    void display() const;

    [[nodiscard]] Iterator<T> getIterator() const;
};

#include "Deque.cpp"

#endif