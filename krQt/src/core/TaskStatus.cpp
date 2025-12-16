#include "core/TaskStatus.h"

std::string TaskStatus::toString(bool isCompleted) {
    return isCompleted ? "ВЫПОЛНЕНО" : "В РАБОТЕ";
}

QString TaskStatus::toQString(bool isCompleted) {
    return QString::fromStdString(toString(isCompleted));
}