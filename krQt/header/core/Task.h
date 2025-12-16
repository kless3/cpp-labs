#pragma once

#include <string>
#include <string_view>
#include <QString>

class Task {
public:
    Task(std::string description, std::string date, std::string time, int priority);

    int getId() const;
    std::string getDescription() const;
    std::string getDate() const;
    std::string getTime() const;
    int getPriority() const;
    bool isCompleted() const;

    void setCompleted(bool value);
    void setDescription(std::string_view desc);
    void setDate(std::string_view dateStr);
    void setTime(std::string_view timeStr);
    void setPriority(int prio);

    std::string getPriorityStars() const;
    QString getPriorityText() const;

private:
    friend class DataPersistenceManager;
    void setId(int taskId);

    static int nextId;
    int id{0};
    std::string description;
    std::string date;
    std::string time;
    int priority;
    bool completed;
};
