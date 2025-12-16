#include "core/Task.h"
#include "core/TaskPriority.h"

int Task::nextId = 1;

Task::Task(std::string description, std::string date, std::string time, int priority)
    : description(std::move(description))
    , date(std::move(date))
    , time(std::move(time))
    , priority(priority)
{
    id = nextId++;
}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const {
    return description;
}

std::string Task::getDate() const {
    return date;
}

std::string Task::getTime() const {
    return time;
}

int Task::getPriority() const {
    return priority;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setCompleted(bool value) {
    completed = value;
}

void Task::setDescription(std::string_view desc) {
    description = desc;
}

void Task::setDate(std::string_view dateStr) {
    date = dateStr;
}

void Task::setTime(std::string_view timeStr) {
    time = timeStr;
}

void Task::setPriority(int prio) {
    priority = prio;
}

void Task::setId(int taskId) {
    id = taskId;
    if (taskId >= nextId) {
        nextId = taskId + 1;
    }
}

std::string Task::getPriorityStars() const {
    return TaskPriority::toStars(priority);
}

QString Task::getPriorityText() const {
    return TaskPriority::toQString(priority);
}
