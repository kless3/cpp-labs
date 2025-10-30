#ifndef LABA8_MENU_H
#define LABA8_MENU_H

#include <iostream>
#include "Queue.h"
#include "Algorithm.h"

template <typename T>
void showMenu();

template <typename T>
void handleEnqueue(Queue<T>& queue);

template <typename T>
void handleDequeue(Queue<T>& queue);

template <typename T>
void handleDisplay(const Queue<T>& queue);

template <typename T>
void handleLinearSearch(const Queue<T>& queue);

template <typename T>
void handleSelectionSort(Queue<T>& queue);

template <typename T>
void handleClear(Queue<T>& queue);

template <typename T>
void runMenu();

#endif