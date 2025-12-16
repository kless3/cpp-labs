#pragma once

#include <string>
#include <QString>

class TaskStatus {
public:
    enum class State {
        PENDING,
        COMPLETED
    };

    static std::string toString(bool isCompleted);
    static QString toQString(bool isCompleted);
};