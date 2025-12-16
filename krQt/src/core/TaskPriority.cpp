#include "core/TaskPriority.h"
#include <format>

std::string TaskPriority::toString(int priority) {
    using enum Level;
    
    switch (priority) {
        case std::to_underlying(LOW):       return "Низкий";
        case std::to_underlying(MEDIUM):    return "Средний";
        case std::to_underlying(HIGH):       return "Высокий";
        case std::to_underlying(IMPORTANT):  return "Важный";
        case std::to_underlying(CRITICAL):  return "Критичный";
        default:                             return "Неизвестно";
    }
}

QString TaskPriority::toQString(int priority) {
    return QString::fromStdString(toString(priority));
}

std::string TaskPriority::toStars(int priority) {
    return std::string(priority, '*') + std::string(5 - priority, ' ');
}