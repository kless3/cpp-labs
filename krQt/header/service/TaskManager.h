#pragma once

#include "repository/TaskRepository.h"
#include "repository/TaskSorter.h"
#include "repository/TaskFilter.h"
#include "repository/DataPersistenceManager.h"

#include <vector>
#include <string>

class TaskManager {
public:
    void addTask(const std::string& desc, const std::string& date, const std::string& time, int priority);
    void editTask(int id, const std::string& newDescription, int newPriority);
    void markCompleted(int id);
    void unmarkCompleted(int id);
    void deleteTask(int id);

    std::vector<Task> getAllTasks() const;
    std::vector<Task> getTasksByDate(const std::string& date) const;
    std::vector<Task> getCompleted() const;
    std::vector<Task> getPending() const;
    std::vector<Task> getHighPriority() const;
    std::vector<Task> searchByDescription(const std::string& keyword) const;

    void sortByDate();
    void sortByPriority();

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    TaskRepository repository;
};
