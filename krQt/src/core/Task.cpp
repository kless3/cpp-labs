#include "core/Task.h"
#include "core/TaskPriority.h"

int Task::nextId = 1;

Task::Task(std::string description, std::string date, std::string time, int priority)
    : id(nextId++)
    , description(std::move(description))
    , date(std::move(date))
    , time(std::move(time))
    , priority(priority)
    , completed(false)
{
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

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

void Task::setDate(const std::string& date) {
    this->date = date;
}

void Task::setTime(const std::string& time) {
    this->time = time;
}

void Task::setPriority(int priority) {
    this->priority = priority;
}

void Task::setId(int id) {
    this->id = id;
    if (id >= nextId) {
        nextId = id + 1;
    }
}

std::string Task::getPriorityStars() const {
    return TaskPriority::toStars(priority);
}

QString Task::getPriorityText() const {
    return TaskPriority::toQString(priority);
}
