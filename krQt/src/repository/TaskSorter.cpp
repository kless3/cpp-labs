#include "repository/TaskSorter.h"

#include <algorithm>
#include <ranges>

void TaskSorter::sortByDate(std::vector<Task>& tasks) {
    std::ranges::sort(tasks, compareByDate);
}

void TaskSorter::sortByPriority(std::vector<Task>& tasks) {
    std::ranges::sort(tasks, compareByPriority);
}

void TaskSorter::sortByStatus(std::vector<Task>& tasks) {
    std::ranges::sort(tasks, compareByStatus);
}

bool TaskSorter::compareByDate(const Task& a, const Task& b) {
    if (a.getDate() != b.getDate()) {
        return a.getDate() < b.getDate();
    }
    return a.getTime() < b.getTime();
}

bool TaskSorter::compareByPriority(const Task& a, const Task& b) {
    if (a.getPriority() != b.getPriority()) {
        return a.getPriority() > b.getPriority();
    }
    return compareByDate(a, b);
}

bool TaskSorter::compareByStatus(const Task& a, const Task& b) {
    if (a.isCompleted() != b.isCompleted()) {
        return a.isCompleted() < b.isCompleted();
    }
    return compareByPriority(a, b);
}
