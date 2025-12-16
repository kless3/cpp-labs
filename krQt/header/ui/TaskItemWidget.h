#pragma once

#include "core/Task.h"

#include <QWidget>

class QLabel;
class QPushButton;

class TaskItemWidget : public QWidget {
    Q_OBJECT

public:
    explicit TaskItemWidget(const Task& task, QWidget* parent = nullptr);

signals:
    void taskCompleted(int id);
    void taskUncompleted(int id);
    void taskDeleted(int id);
    void taskEdited(int id);

private slots:
    void onCompleteClicked();
    void onDeleteClicked();
    void onEditClicked();

private:
    void setupUI();
    void applyStyle();

    int taskId;
    bool isCompleted;
    QLabel* descriptionLabel;
    QLabel* timeLabel;
    QLabel* priorityLabel;
    QPushButton* completeButton;
    QPushButton* deleteButton;
    QPushButton* editButton;
};
