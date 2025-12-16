#include "service/NotificationService.h"
#include "service/DateService.h"

NotificationService::NotificationService(QObject* parent)
    : QObject(parent)
{
}

void NotificationService::checkUpcomingTasks(const std::vector<Task>& tasks) {
    for (const auto& task : tasks) {
        if (isTaskUpcoming(task) && !task.isCompleted()) {
            QString message = QString("Предстоящая задача: %1 в %2")
                .arg(QString::fromStdString(task.getDescription()))
                .arg(QString::fromStdString(task.getTime()));
            emit upcomingTaskDetected(message);
        }
    }
}

bool NotificationService::isTaskUpcoming(const Task& task) const {
    QString taskDate = QString::fromStdString(task.getDate());
    return DateService::isToday(taskDate) || DateService::isTomorrow(taskDate);
}
