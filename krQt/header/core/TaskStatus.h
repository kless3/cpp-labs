#pragma once

#include <string>
#include <QString>

class TaskStatus {
public:
    enum State {
        PENDING,
        COMPLETED
    };

    static std::string toString(bool isCompleted);
    static QString toQString(bool isCompleted);
};
