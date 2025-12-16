#pragma once

#include "core/Task.h"

#include <vector>
#include <string>

class TaskFilter {
public:
    static std::vector<Task> filterCompleted(const std::vector<Task>& tasks);
    static std::vector<Task> filterPending(const std::vector<Task>& tasks);
    static std::vector<Task> filterHighPriority(const std::vector<Task>& tasks);
    static std::vector<Task> filterByDate(const std::vector<Task>& tasks, const std::string& date);
    static std::vector<Task> searchByDescription(const std::vector<Task>& tasks, const std::string& keyword);
};
