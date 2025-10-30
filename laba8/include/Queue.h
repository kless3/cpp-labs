#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include "Iterator.h"
#include <iostream>

template<typename T>
class Queue {
private:
    Node<T>* front = nullptr;
    Node<T>* rear = nullptr;
    int size = 0;

    void copyFrom(const Queue& other) {
        Node<T>* current = other.front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }

public:
    Queue() = default;

    ~Queue() noexcept {
        clear();
    }

    Queue(const Queue& other) {
        copyFrom(other);
    }

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    Queue(Queue&& other) noexcept
            : front(other.front), rear(other.rear), size(other.size) {
        other.front = nullptr;
        other.rear = nullptr;
        other.size = 0;
    }

    Queue& operator=(Queue&& other) noexcept {
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

    void enqueue(const T& value) {
        auto newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            return T();
        }
        Node<T>* temp = front;
        T value = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
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
            dequeue();
        }
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node<T>* current = front;
        std::cout << "Queue: ";
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