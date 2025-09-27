#ifndef QUEUE_H
#define QUEUE_H

class Node {
public:
    int data;
    Node* next = nullptr;
    explicit Node(int value);
};

class Queue {
private:
    Node* front = nullptr;
    Node* rear = nullptr;
    int size = 0;

    void copyFrom(const Queue& other);

public:
    Queue();
    ~Queue();

    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;

    void enqueue(int value);
    int dequeue();
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int getSize() const;
    void clear();
    void display() const;

    class Iterator {
    private:
        Node* current = nullptr;
    public:
        explicit Iterator(Node* start);
        void next();
        [[nodiscard]] bool hasNext() const;
        [[nodiscard]] int getValue() const;
    };

    [[nodiscard]] Iterator getIterator() const;
};

class Algorithm {
public:
    static int linearSearch(const Queue& queue, int target);
    static void bubbleSort(Queue& queue);
};

#endif