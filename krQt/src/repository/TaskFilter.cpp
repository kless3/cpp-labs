#include "repository/TaskFilter.h"

#include <algorithm>

std::vector<Task> TaskFilter::filterCompleted(const std::vector<Task>& tasks) {
    std::vector<Task> result;
    std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(result),
                 [](const Task& task) { return task.isCompleted(); });
    return result;
}

std::vector<Task> TaskFilter::filterPending(const std::vector<Task>& tasks) {
    std::vector<Task> result;
    std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(result),
                 [](const Task& task) { return !task.isCompleted(); });
    return result;
}

std::vector<Task> TaskFilter::filterHighPriority(const std::vector<Task>& tasks) {
    std::vector<Task> result;
    std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(result),
                 [](const Task& task) { return task.getPriority() >= 4; });
    return result;
}

std::vector<Task> TaskFilter::filterByDate(const std::vector<Task>& tasks, const std::string& date) {
    std::vector<Task> result;
    std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(result),
                 [&date](const Task& task) { return task.getDate() == date; });
    return result;
}

std::vector<Task> TaskFilter::searchByDescription(const std::vector<Task>& tasks, const std::string& keyword) {
    std::vector<Task> result;
    std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(result),
                 [&keyword](const Task& task) {
                     return task.getDescription().find(keyword) != std::string::npos;
                 });
    return result;
}
