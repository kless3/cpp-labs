#ifndef LABA8_MENU_H
#define LABA8_MENU_H

#include <iostream>
#include "Deque.h"
#include "Algorithm.h"

template <typename T>
void showMenu();

template <typename T>
void handleEnqueueFront(Deque<T>& deque);

template <typename T>
void handleEnqueueRear(Deque<T>& deque);

template <typename T>
void handleDequeueFront(Deque<T>& deque);

template <typename T>
void handleDequeueRear(Deque<T>& deque);

template <typename T>
void handleDisplay(const Deque<T>& deque);

template <typename T>
void handleLinearSearch(const Deque<T>& deque);

template <typename T>
void handleSelectionSort(Deque<T>& deque);

template <typename T>
void handleClear(Deque<T>& deque);

template <typename T>
void runMenu();


#endif