#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class [[maybe_unused]] Queue {
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int count;

    void resize();

public:
    explicit Queue(int initialCapacity = 10);
    ~Queue();
    bool enqueue(const T& item);
    bool dequeue(T& result);
    bool peek(T& result);
    [[nodiscard]] bool isEmpty() const;

    [[maybe_unused]] [[nodiscard]] int size() const;
    void clear();
};

#include "../src/Queue.cpp"

#endif