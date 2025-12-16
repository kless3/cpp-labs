#pragma once

#include <string>
#include <QString>

class TaskPriority {
public:
    enum class Level {
        LOW = 1,
        MEDIUM = 2,
        HIGH = 3,
        IMPORTANT = 4,
        CRITICAL = 5
    };

    static std::string toString(int priority);
    static QString toQString(int priority);
    static std::string toStars(int priority);
};