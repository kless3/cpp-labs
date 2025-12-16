#include "core/TaskPriority.h"

std::string TaskPriority::toString(int priority) {
    switch (priority) {
        case static_cast<int>(Level::LOW):       return "Низкий";
        case static_cast<int>(Level::MEDIUM):    return "Средний";
        case static_cast<int>(Level::HIGH):      return "Высокий";
        case static_cast<int>(Level::IMPORTANT): return "Важный";
        case static_cast<int>(Level::CRITICAL):  return "Критичный";
        default:        return "Неизвестно";
    }
}

QString TaskPriority::toQString(int priority) {
    return QString::fromStdString(toString(priority));
}

std::string TaskPriority::toStars(int priority) {
    return std::string(priority, '*') + std::string(5 - priority, ' ');
}