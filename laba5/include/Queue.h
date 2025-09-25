#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int count;

    void resize();

public:
    Queue(int initialCapacity = 10);
    ~Queue();

    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;

    bool enqueue(const T& item);
    bool dequeue(T& result);
    bool peek(T& result);
    bool isEmpty() const;
    int size() const;
    void clear();
};

#include "../src/Queue.cpp"

#endif