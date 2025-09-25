#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    T* data = nullptr;
    int capacity = 10;
    int front = 0;
    int rear = -1;
    int count = 0;

    void resize();

public:
    explicit Queue(int initialCapacity = 10);
    ~Queue();

    [[maybe_unused]] Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    [[maybe_unused]] Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;

    bool enqueue(const T& item);
    bool dequeue(T& result);
    bool peek(T& result);
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int size() const;
    void clear();
};

#include "../src/Queue.cpp"

#endif