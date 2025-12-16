#pragma once

#include <QDate>
#include <QString>

class DateService {
public:
    static QString getCurrentDateString();
    static QString getTomorrowDateString();
    static QString formatDate(const QDate& date);
    static QString getDayOfWeek(const QDate& date);
    static bool isToday(const QString& dateString);
    static bool isTomorrow(const QString& dateString);
};
