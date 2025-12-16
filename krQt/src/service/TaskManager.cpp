#include "service/TaskManager.h"

void TaskManager::addTask(const std::string& desc, const std::string& date,
                          const std::string& time, int priority) {
    Task task(desc, date, time, priority);
    repository.addTask(task);
}

void TaskManager::editTask(int id, const std::string& newDescription, int newPriority) {
    Task* task = repository.findTaskById(id);
    if (task != nullptr) {
        Task updatedTask = *task;
        updatedTask.setDescription(newDescription);
        updatedTask.setPriority(newPriority);
        repository.updateTask(updatedTask);
    }
}

void TaskManager::markCompleted(int id) {
    Task* task = repository.findTaskById(id);
    if (task != nullptr) {
        Task updatedTask = *task;
        updatedTask.setCompleted(true);
        repository.updateTask(updatedTask);
    }
}

void TaskManager::unmarkCompleted(int id) {
    Task* task = repository.findTaskById(id);
    if (task != nullptr) {
        Task updatedTask = *task;
        updatedTask.setCompleted(false);
        repository.updateTask(updatedTask);
    }
}

void TaskManager::deleteTask(int id) {
    repository.removeTask(id);
}

std::vector<Task> TaskManager::getAllTasks() const {
    return repository.getAllTasks();
}

std::vector<Task> TaskManager::getTasksByDate(const std::string& date) const {
    return repository.findTasksByDate(date);
}

std::vector<Task> TaskManager::getCompleted() const {
    return repository.findTasksByStatus(true);
}

std::vector<Task> TaskManager::getPending() const {
    return repository.findTasksByStatus(false);
}

std::vector<Task> TaskManager::getHighPriority() const {
    return repository.findTasksByPriority(4);
}

std::vector<Task> TaskManager::searchByDescription(const std::string& keyword) const {
    return repository.searchTasks(keyword);
}

void TaskManager::sortByDate() {
    auto tasks = repository.getAllTasks();
    TaskSorter::sortByDate(tasks);
    repository.updateTasksOrder(tasks);
}

void TaskManager::sortByPriority() {
    auto tasks = repository.getAllTasks();
    TaskSorter::sortByPriority(tasks);
    repository.updateTasksOrder(tasks);
}

void TaskManager::saveToFile(const std::string& filename) const {
    DataPersistenceManager::saveToFile(repository.getAllTasks(), filename);
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::vector<Task> tasks;
    if (DataPersistenceManager::loadFromFile(tasks, filename)) {
        repository.clear();
        for (const auto& task : tasks) {
            repository.addTask(task);
        }
    }
}
