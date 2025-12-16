#pragma once

#include "core/Task.h"

#include <vector>
#include <QObject>

class NotificationService : public QObject {
    Q_OBJECT

public:
    explicit NotificationService(QObject* parent = nullptr);

    void checkUpcomingTasks(const std::vector<Task>& tasks);

signals:
    void upcomingTaskDetected(const QString& message);

private:
    bool isTaskUpcoming(const Task& task) const;
};
