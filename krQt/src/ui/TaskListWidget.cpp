#include "ui/TaskListWidget.h"
#include "ui/TaskItemWidget.h"
#include "ui/EditTaskDialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QMessageBox>

#include <algorithm>

TaskListWidget::TaskListWidget(const QString& title, TaskManager* taskManager, QWidget* parent)
    : QWidget(parent)
    , taskManager(taskManager)
    , title(title)
{
    setupUI();
}

void TaskListWidget::setupUI() {
    auto* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    titleLabel = new QLabel(title);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; padding: 12px;");

    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setStyleSheet("QScrollArea { border: none; background: transparent; }");

    auto* container = new QWidget();
    tasksLayout = new QVBoxLayout(container);
    tasksLayout->setSpacing(8);
    tasksLayout->setContentsMargins(10, 10, 10, 10);
    tasksLayout->addStretch();

    scrollArea->setWidget(container);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(scrollArea);
}

void TaskListWidget::displayTasksForDate(const QString& date) {
    clearLayout();

    std::vector<Task> tasks = taskManager->getTasksByDate(date.toStdString());

    for (const auto& task : tasks) {
        auto* taskWidget = new TaskItemWidget(task, this);

        connect(taskWidget, &TaskItemWidget::taskCompleted, [this](int id) {
            taskManager->markCompleted(id);
            emit tasksUpdated();
        });

        connect(taskWidget, &TaskItemWidget::taskUncompleted, [this](int id) {
            taskManager->unmarkCompleted(id);
            emit tasksUpdated();
        });

        connect(taskWidget, &TaskItemWidget::taskDeleted, [this](int id) {
            auto reply = QMessageBox::question(this, "Удалить задачу",
                                               "Вы уверены, что хотите удалить эту задачу?",
                                               QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                taskManager->deleteTask(id);
                emit tasksUpdated();
            }
        });

        connect(taskWidget, &TaskItemWidget::taskEdited, [this](int id) {
            auto allTasks = taskManager->getAllTasks();
            auto it = std::find_if(allTasks.begin(), allTasks.end(),
                                   [id](const Task& t) { return t.getId() == id; });
            if (it != allTasks.end()) {
                EditTaskDialog dialog(*it, this);
                if (dialog.exec() == QDialog::Accepted) {
                    taskManager->editTask(id,
                                          dialog.getDescription().toStdString(),
                                          dialog.getPriority());
                    emit tasksUpdated();
                }
            }
        });

        tasksLayout->insertWidget(tasksLayout->count() - 1, taskWidget);
    }
}

void TaskListWidget::setTitle(const QString& newTitle) {
    title = newTitle;
    titleLabel->setText(newTitle);
}

void TaskListWidget::clearLayout() {
    while (tasksLayout->count() > 1) {
        QLayoutItem* item = tasksLayout->takeAt(0);
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}
