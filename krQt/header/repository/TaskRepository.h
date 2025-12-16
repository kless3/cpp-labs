#pragma once

#include "core/Task.h"
#include "Repository.h"

#include <string>

class TaskRepository : public Repository<Task> {
public:
    void addTask(const Task& task);
    void removeTask(int id);
    void updateTask(const Task& updatedTask);
    void updateTasksOrder(const std::vector<Task>& sortedTasks);

    Task* findTaskById(int id);
    std::vector<Task> getAllTasks() const;
    std::vector<Task> findTasksByDate(const std::string& date) const;
    std::vector<Task> findTasksByStatus(bool completed) const;
    std::vector<Task> findTasksByPriority(int minPriority) const;
    std::vector<Task> searchTasks(const std::string& keyword) const;
};
