#include "core/TaskPriority.h"

std::string TaskPriority::toString(int priority) {
    switch (priority) {
        case LOW:       return "Низкий";
        case MEDIUM:    return "Средний";
        case HIGH:      return "Высокий";
        case IMPORTANT: return "Важный";
        case CRITICAL:  return "Критичный";
        default:        return "Неизвестно";
    }
}

QString TaskPriority::toQString(int priority) {
    return QString::fromStdString(toString(priority));
}

std::string TaskPriority::toStars(int priority) {
    return std::string(priority, '*') + std::string(5 - priority, ' ');
}
