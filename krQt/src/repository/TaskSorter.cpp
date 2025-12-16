#include "repository/TaskSorter.h"

#include <algorithm>

void TaskSorter::sortByDate(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), compareByDate);
}

void TaskSorter::sortByPriority(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), compareByPriority);
}

void TaskSorter::sortByStatus(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), compareByStatus);
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
