#ifndef DEQUE_H
#define DEQUE_H

class Node {
public:
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
    explicit Node(int value);
};

class Deque {
private:
    Node* front = nullptr;
    Node* rear = nullptr;
    int size = 0;

    void copyFrom(const Deque& other);

public:
    Deque();
    ~Deque();

    Deque(const Deque& other);
    Deque& operator=(const Deque& other);
    Deque(Deque&& other) noexcept;
    Deque& operator=(Deque&& other) noexcept;

    void enqueueFront(int value);
    void enqueueRear(int value);
    int dequeueFront();
    int dequeueRear();
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
    static int linearSearch(const Deque& deque, int target);
    static void bubbleSort(Deque& deque);
};

#endif