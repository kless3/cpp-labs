#pragma once

#include "service/TaskManager.h"

#include <QWidget>

class QVBoxLayout;
class QScrollArea;
class QLabel;

class TaskListWidget : public QWidget {
    Q_OBJECT

public:
    explicit TaskListWidget(const QString& title, TaskManager* taskManager, QWidget* parent = nullptr);

    void displayTasksForDate(const QString& date);
    void setTitle(const QString& newTitle);

signals:
    void tasksUpdated();

private:
    void clearLayout();
    void setupUI();

    TaskManager* taskManager;
    QVBoxLayout* tasksLayout;
    QScrollArea* scrollArea;
    QLabel* titleLabel;
    QString title;
};
