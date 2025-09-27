#include "../include/Queue.h"
#include <iostream>

Node::Node(int value) : data(value), next(nullptr) {}

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() {
    clear();
}

void Queue::enqueue(int value) {
    auto newNode = new Node(value);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        return -1;
    }
    Node* temp = front;
    int value = temp->data;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    size--;
    return value;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

int Queue::getSize() const {
    return size;
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node* current = front;
    std::cout << "Queue: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Queue::Iterator::Iterator(Node* start) : current(start) {}

void Queue::Iterator::next() {
    if (current != nullptr) {
        current = current->next;
    }
}

bool Queue::Iterator::hasNext() const {
    return current != nullptr;
}

int Queue::Iterator::getValue() const {
    return current->data;
}

Queue::Iterator Queue::getIterator() const {
    return Iterator(front);
}

int Algorithm::linearSearch(const Queue& queue, int target) {
    Queue::Iterator it = queue.getIterator();
    int index = 0;
    while (it.hasNext()) {
        if (it.getValue() == target) {
            return index;
        }
        it.next();
        index++;
    }
    return -1;
}

void Algorithm::bubbleSort(Queue& queue) {
    int n = queue.getSize();
    if (n <= 1) return;

    auto arr = new int[n];
    Queue::Iterator it = queue.getIterator();
    for (int i = 0; i < n; i++) {
        arr[i] = it.getValue();
        it.next();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    queue.clear();
    for (int i = 0; i < n; i++) {
        queue.enqueue(arr[i]);
    }

    delete[] arr;
}
void Queue::copyFrom(const Queue& other) {
    front = rear = nullptr;
    size = 0;

    Node* current = other.front;
    while (current != nullptr) {
        enqueue(current->data);
        current = current->next;
    }
}

Queue::Queue(const Queue& other) : front(nullptr), rear(nullptr), size(0) {
    copyFrom(other);
}

Queue& Queue::operator=(const Queue& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Queue::Queue(Queue&& other) noexcept
        : front(other.front), rear(other.rear), size(other.size) {
    other.front = nullptr;
    other.rear = nullptr;
    other.size = 0;
}

Queue& Queue::operator=(Queue&& other) noexcept {
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