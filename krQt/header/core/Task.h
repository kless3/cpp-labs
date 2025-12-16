#pragma once

#include <string>
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

    void setCompleted(bool completed);
    void setDescription(const std::string& description);
    void setDate(const std::string& date);
    void setTime(const std::string& time);
    void setPriority(int priority);

    std::string getPriorityStars() const;
    QString getPriorityText() const;

private:
    friend class DataPersistenceManager;
    void setId(int id);

    static int nextId;
    int id;
    std::string description;
    std::string date;
    std::string time;
    int priority;
    bool completed;
};
