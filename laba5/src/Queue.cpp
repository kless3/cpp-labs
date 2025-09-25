#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "../include/Queue.h"

template <typename T>
Queue<T>::Queue(int initialCapacity)
        : capacity(initialCapacity), data(new T[capacity]) {
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
        : capacity(other.capacity),
          front(other.front),
          rear(other.rear),
          count(other.count),
          data(new T[capacity]) {
    for (int i = 0; i < capacity; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        delete[] data;

        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        count = other.count;

        data = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept
        : data(other.data),
          capacity(other.capacity),
          front(other.front),
          rear(other.rear),
          count(other.count) {
    other.data = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.rear = -1;
    other.count = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept {
    if (this != &other) {
        delete[] data;

        data = other.data;
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        count = other.count;

        other.data = nullptr;
        other.capacity = 0;
        other.front = 0;
        other.rear = -1;
        other.count = 0;
    }
    return *this;
}

template <typename T>
void Queue<T>::resize() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];

    for (int i = 0; i < count; i++) {
        newData[i] = data[(front + i) % capacity];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    front = 0;
    rear = count - 1;
}

template <typename T>
bool Queue<T>::enqueue(const T& item) {
    if (count == capacity) {
        resize();
    }

    rear = (rear + 1) % capacity;
    data[rear] = item;
    count++;
    return true;
}

template <typename T>
bool Queue<T>::dequeue(T& result) {
    if (isEmpty()) {
        return false;
    }

    result = data[front];
    front = (front + 1) % capacity;
    count--;
    return true;
}

template <typename T>
bool Queue<T>::peek(T& result) {
    if (isEmpty()) {
        return false;
    }

    result = data[front];
    return true;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
void Queue<T>::clear() {
    front = 0;
    rear = -1;
    count = 0;
}

#endif