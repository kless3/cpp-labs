#ifndef LABA8_MENU_H
#define LABA8_MENU_H

#include <iostream>
#include "../include/Queue.h"

void showMenu();

void handleEnqueue(Queue &queue);

void handleDequeue(Queue &queue);

void handleDisplay(const Queue &queue);

void handleLinearSearch(const Queue &queue);

void handleBubbleSort(Queue &queue);

void handleClear(Queue &queue);

#endif //LABA8_MENU_H
