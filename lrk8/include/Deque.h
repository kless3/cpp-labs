#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"
#include "Iterator.h"
#include <iostream>

template<typename T>
class Deque {
private:
    Node<T>* front = nullptr;
    Node<T>* rear = nullptr;
    int size = 0;

    void copyFrom(const Deque& other) {
        Node<T>* current = other.front;
        while (current != nullptr) {
            enqueueRear(current->data);
            current = current->next;
        }
    }

public:
    Deque() = default;

    ~Deque() noexcept {
        clear();
    }

    Deque(const Deque& other) {
        copyFrom(other);
    }

    Deque& operator=(const Deque& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    Deque(Deque&& other) noexcept
            : front(other.front), rear(other.rear), size(other.size) {
        other.front = nullptr;
        other.rear = nullptr;
        other.size = 0;
    }

    Deque& operator=(Deque&& other) noexcept {
        if (this != &other) {
            clear();
            front = other.front;
            rear = other.rear;
            size = other.size;
            other.front = nullptr;
            other.rear = nullptr;
            other.size = 0;
        }
        return *this;
    }

    void enqueueFront(const T& value) {
        auto newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void enqueueRear(const T& value) {
        auto newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeueFront() noexcept {
        if (isEmpty()) {
            return T();
        }
        Node<T>* temp = front;
        T value = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    T dequeueRear() noexcept {
        if (isEmpty()) {
            return T();
        }
        Node<T>* temp = rear;
        T value = temp->data;
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    [[nodiscard]] bool isEmpty() const {
        return front == nullptr;
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    void clear() noexcept {
        while (!isEmpty()) {
            dequeueFront();
        }
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        Node<T>* current = front;
        std::cout << "Deque: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    [[nodiscard]] Iterator<T> getIterator() const {
        return Iterator<T>(front);
    }
};

#endif