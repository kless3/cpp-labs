#ifndef LABA8_MENU_H
#define LABA8_MENU_H

#include <iostream>
#include "../include/Deque.h"

void showMenu();

void handleEnqueueFront(Deque &deque);
void handleEnqueueRear(Deque &deque);
void handleDequeueFront(Deque &deque);
void handleDequeueRear(Deque &deque);
void handleDisplay(const Deque &deque);
void handleLinearSearch(const Deque &deque);
void handleBubbleSort(Deque &deque);
void handleClear(Deque &deque);

#endif