#include "../include/Deque.h"
#include <iostream>
#include <stdexcept>

Node::Node(int value) : data(value) {}

Deque::Deque() = default;

Deque::~Deque() {
    clear();
}

void Deque::copyFrom(const Deque& other) {
    Node* current = other.front;
    while (current != nullptr) {
        enqueueRear(current->data);
        current = current->next;
    }
}

Deque::Deque(const Deque& other) {
    copyFrom(other);
}

Deque& Deque::operator=(const Deque& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Deque::Deque(Deque&& other) noexcept
        : front(other.front), rear(other.rear), size(other.size) {
    other.front = nullptr;
    other.rear = nullptr;
    other.size = 0;
}

Deque& Deque::operator=(Deque&& other) noexcept {
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

void Deque::enqueueFront(int value) {
    auto newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

void Deque::enqueueRear(int value) {
    auto newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

int Deque::dequeueFront() {
    if (isEmpty()) {
        return -1;
    }
    Node* temp = front;
    int value = temp->data;
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

int Deque::dequeueRear() {
    if (isEmpty()) {
        return -1;
    }
    Node* temp = rear;
    int value = temp->data;
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

bool Deque::isEmpty() const {
    return front == nullptr;
}

int Deque::getSize() const {
    return size;
}

void Deque::clear() {
    while (!isEmpty()) {
        dequeueFront();
    }
}

void Deque::display() const {
    if (isEmpty()) {
        std::cout << "Deque is empty" << std::endl;
        return;
    }
    Node* current = front;
    std::cout << "Deque: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Deque::Iterator::Iterator(Node* start) : current(start) {}

void Deque::Iterator::next() {
    if (current != nullptr) {
        current = current->next;
    }
}

bool Deque::Iterator::hasNext() const {
    return current != nullptr;
}

int Deque::Iterator::getValue() const {
    return current->data;
}

Deque::Iterator Deque::getIterator() const {
    return Iterator(front);
}

int Algorithm::linearSearch(const Deque& deque, int target) {
    Deque::Iterator it = deque.getIterator();
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

void Algorithm::bubbleSort(Deque& deque) {
    int n = deque.getSize();
    if (n <= 1) return;

    auto arr = new int[n];
    Deque::Iterator it = deque.getIterator();
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

    deque.clear();
    for (int i = 0; i < n; i++) {
        deque.enqueueRear(arr[i]);
    }

    delete[] arr;
}