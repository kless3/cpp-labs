#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "../include/Queue.h"

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {
    clear();
}

template <typename T>
bool Queue<T>::enqueue(const T& item) {
    auto* newNode = new Node<T>(item);

    // Всегда проверяем оба указателя
    if (front == nullptr) {
        // Очередь пуста - инициализируем оба указателя
        front = rear = newNode;
    } else if (rear == nullptr) {
        // Некорректное состояние - но front не nullptr
        // Восстанавливаем структуру
        rear = newNode;
        front->next = newNode;  // Связываем front с новым узлом
    } else {
        // Нормальное состояние - добавляем в конец
        rear->next = newNode;
        rear = newNode;
    }

    count++;
    return true;
}

template <typename T>
bool Queue<T>::dequeue(T& result) {
    if (isEmpty()) {
        return false;
    }

    Node<T>* temp = front;
    result = front->data;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    count--;
    return true;
}

template <typename T>
bool Queue<T>::peek(T& result) {
    if (isEmpty()) {
        return false;
    }

    result = front->data;
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
void Queue<T>::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    Node<T>* current = front;
    std::cout << "Queue contents (front to rear): ";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void Queue<T>::clear() {
    Node<T>* current = front;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    front = nullptr;
    rear = nullptr;
    count = 0;
}

#endif