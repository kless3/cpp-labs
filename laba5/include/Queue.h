#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int count;

public:
    Queue();
    ~Queue();
    bool enqueue(const T& item);
    bool dequeue(T& result);
    bool peek(T& result);
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int size() const;
    void display();
    void clear();
};

#include "../src/Queue.cpp"

#endif