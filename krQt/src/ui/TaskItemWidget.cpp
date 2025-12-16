#include "ui/TaskItemWidget.h"
#include "ui/EditTaskDialog.h"
#include "service/TaskManager.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

TaskItemWidget::TaskItemWidget(const Task& task, QWidget* parent)
    : QWidget(parent)
    , taskId(task.getId())
    , isCompleted(task.isCompleted())
{
    setupUI();
    applyStyle();

    descriptionLabel->setText(QString::fromStdString(task.getDescription()));
    timeLabel->setText(QString::fromStdString(task.getTime()));
    priorityLabel->setText(QString::fromStdString(task.getPriorityStars()));

    completeButton->setText(isCompleted ? "↶" : "✓");
    completeButton->setToolTip(isCompleted ? "Восстановить" : "Выполнить");
}

void TaskItemWidget::setupUI() {
    setFixedHeight(90);

    auto* layout = new QHBoxLayout(this);
    layout->setContentsMargins(12, 8, 12, 8);
    layout->setSpacing(12);

    auto* contentLayout = new QVBoxLayout();
    contentLayout->setSpacing(4);

    descriptionLabel = new QLabel();
    descriptionLabel->setWordWrap(true);

    auto* metaLayout = new QHBoxLayout();
    metaLayout->setSpacing(12);

    timeLabel = new QLabel();
    priorityLabel = new QLabel();

    metaLayout->addWidget(timeLabel);
    metaLayout->addWidget(priorityLabel);
    metaLayout->addStretch();

    contentLayout->addWidget(descriptionLabel);
    contentLayout->addLayout(metaLayout);

    auto* buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(6);

    completeButton = new QPushButton();
    completeButton->setFixedSize(42, 42);

    editButton = new QPushButton("✎");
    editButton->setFixedSize(42, 42);
    editButton->setToolTip("Редактировать");

    deleteButton = new QPushButton("✕");
    deleteButton->setFixedSize(42, 42);
    deleteButton->setToolTip("Удалить");

    buttonLayout->addWidget(completeButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(deleteButton);

    layout->addLayout(contentLayout, 1);
    layout->addLayout(buttonLayout);

    connect(completeButton, &QPushButton::clicked, this, &TaskItemWidget::onCompleteClicked);
    connect(editButton, &QPushButton::clicked, this, &TaskItemWidget::onEditClicked);
    connect(deleteButton, &QPushButton::clicked, this, &TaskItemWidget::onDeleteClicked);
}

void TaskItemWidget::applyStyle() {
    setStyleSheet(R"(
        TaskItemWidget {
            background: white;
            border: 1px solid #ddd;
            border-radius: 8px;
            margin: 4px;
        }
        QLabel {
            background: transparent;
            border: none;
        }
    )");

    descriptionLabel->setStyleSheet(
        QString("font-size: 14px; color: %1; text-decoration: %2; font-weight: 500;")
            .arg(isCompleted ? "#888" : "#000")
            .arg(isCompleted ? "line-through" : "none")
    );

    timeLabel->setStyleSheet(
        "font-size: 12px; color: #666; background: #f5f5f5; padding: 2px 6px; border-radius: 3px;"
    );

    priorityLabel->setStyleSheet(
        "font-size: 12px; color: #333; font-weight: bold; background: #fff3cd; "
        "padding: 2px 6px; border-radius: 3px;"
    );

    completeButton->setStyleSheet(R"(
        QPushButton {
            background: #28a745;
            color: white;
            border: none;
            border-radius: 5px;
            font-size: 14px;
            font-weight: bold;
        }
        QPushButton:hover {
            background: #218838;
        }
        QPushButton:pressed {
            background: #1e7e34;
        }
    )");

    editButton->setStyleSheet(R"(
        QPushButton {
            background: #ffc107;
            color: white;
            border: none;
            border-radius: 5px;
            font-size: 14px;
            font-weight: bold;
        }
        QPushButton:hover {
            background: #e0a800;
        }
        QPushButton:pressed {
            background: #d39e00;
        }
    )");

    deleteButton->setStyleSheet(R"(
        QPushButton {
            background: #dc3545;
            color: white;
            border: none;
            border-radius: 5px;
            font-size: 14px;
            font-weight: bold;
        }
        QPushButton:hover {
            background: #c82333;
        }
        QPushButton:pressed {
            background: #bd2130;
        }
    )");
}

void TaskItemWidget::onCompleteClicked() {
    if (isCompleted) {
        emit taskUncompleted(taskId);
    } else {
        emit taskCompleted(taskId);
    }
}

void TaskItemWidget::onDeleteClicked() {
    emit taskDeleted(taskId);
}

void TaskItemWidget::onEditClicked() {
    emit taskEdited(taskId);
}
