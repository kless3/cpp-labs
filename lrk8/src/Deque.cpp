#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "../include/Deque.h"
#include <iostream>

template <typename T>
void Deque<T>::copyFrom(const Deque& other) {
    Node<T>* current = other.front;
    while (current != nullptr) {
        enqueueRear(current->data);
        current = current->next;
    }
}

template <typename T>
Deque<T>::Deque() = default;

template <typename T>
Deque<T>::~Deque() {
    clear();
}

template <typename T>
Deque<T>::Deque(const Deque& other) {
    copyFrom(other);
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Deque<T>::Deque(Deque&& other) noexcept
        : front(other.front), rear(other.rear), size(other.size) {
    other.front = nullptr;
    other.rear = nullptr;
    other.size = 0;
}

template <typename T>
Deque<T>& Deque<T>::operator=(Deque&& other) noexcept {
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

template <typename T>
void Deque<T>::enqueueFront(const T& value) {
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

template <typename T>
void Deque<T>::enqueueRear(const T& value) {
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

template <typename T>
T Deque<T>::dequeueFront() {
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

template <typename T>
T Deque<T>::dequeueRear() {
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

template <typename T>
bool Deque<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
int Deque<T>::getSize() const {
    return size;
}

template <typename T>
void Deque<T>::clear() {
    while (!isEmpty()) {
        dequeueFront();
    }
}

template <typename T>
void Deque<T>::display() const {
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

template <typename T>
Iterator<T> Deque<T>::getIterator() const {
    return Iterator<T>(front);
}

#endif