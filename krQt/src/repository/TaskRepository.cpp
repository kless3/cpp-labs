#include "repository/TaskRepository.h"

void TaskRepository::addTask(const Task& task) {
    add(task);
}

void TaskRepository::removeTask(int id) {
    remove([id](const Task& task) { return task.getId() == id; });
}

void TaskRepository::updateTask(const Task& updatedTask) {
    update(
        [&updatedTask](const Task& task) { return task.getId() == updatedTask.getId(); },
        updatedTask
    );
}

void TaskRepository::updateTasksOrder(const std::vector<Task>& sortedTasks) {
    setAll(sortedTasks);
}

Task* TaskRepository::findTaskById(int id) {
    return find([id](const Task& task) { return task.getId() == id; });
}

std::vector<Task> TaskRepository::getAllTasks() const {
    return getAll();
}

std::vector<Task> TaskRepository::findTasksByDate(const std::string& date) const {
    return filter([&date](const Task& task) { return task.getDate() == date; });
}

std::vector<Task> TaskRepository::findTasksByStatus(bool completed) const {
    return filter([completed](const Task& task) { return task.isCompleted() == completed; });
}

std::vector<Task> TaskRepository::findTasksByPriority(int minPriority) const {
    return filter([minPriority](const Task& task) { return task.getPriority() >= minPriority; });
}

std::vector<Task> TaskRepository::searchTasks(const std::string& keyword) const {
    return filter([&keyword](const Task& task) {
        return task.getDescription().contains(keyword);
    });
}
