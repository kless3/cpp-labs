#include "service/DateService.h"

QString DateService::getCurrentDateString() {
    return QDate::currentDate().toString("yyyy-MM-dd");
}

QString DateService::getTomorrowDateString() {
    return QDate::currentDate().addDays(1).toString("yyyy-MM-dd");
}

QString DateService::formatDate(const QDate& date) {
    return date.toString("dd.MM.yyyy");
}

QString DateService::getDayOfWeek(const QDate& date) {
    static const QStringList days = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
    return days[date.dayOfWeek() - 1];
}

bool DateService::isToday(const QString& dateString) {
    return dateString == getCurrentDateString();
}

bool DateService::isTomorrow(const QString& dateString) {
    return dateString == getTomorrowDateString();
}
