#pragma once

#include "core/Task.h"

#include <vector>

class TaskSorter {
public:
    static void sortByDate(std::vector<Task>& tasks);
    static void sortByPriority(std::vector<Task>& tasks);
    static void sortByStatus(std::vector<Task>& tasks);

private:
    static bool compareByDate(const Task& a, const Task& b);
    static bool compareByPriority(const Task& a, const Task& b);
    static bool compareByStatus(const Task& a, const Task& b);
};
