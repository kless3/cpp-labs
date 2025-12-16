#include "ui/ControlPanel.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include <QMenu>

ControlPanel::ControlPanel(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void ControlPanel::setupUI() {
    auto* layout = new QHBoxLayout(this);

    addButton = new QPushButton("Добавить задачу");
    addButton->setFixedHeight(40);

    managementButton = new QToolButton();
    managementButton->setText("Управление задачами");
    managementButton->setPopupMode(QToolButton::InstantPopup);
    managementButton->setFixedHeight(40);

    allTasksButton = new QPushButton("Все задачи");
    allTasksButton->setFixedHeight(40);

    saveButton = new QPushButton("Сохранить");
    saveButton->setFixedHeight(40);

    loadButton = new QPushButton("Загрузить");
    loadButton->setFixedHeight(40);

    layout->addWidget(addButton);
    layout->addWidget(managementButton);
    layout->addWidget(allTasksButton);
    layout->addWidget(saveButton);
    layout->addWidget(loadButton);
    layout->addStretch();

    auto* managementMenu = new QMenu(managementButton);

    auto* sortDateAction = managementMenu->addAction("Сортировать по дате");
    auto* sortPriorityAction = managementMenu->addAction("Сортировать по приоритету");
    auto* showCompletedAction = managementMenu->addAction("Выполненные задачи");
    auto* showPendingAction = managementMenu->addAction("Текущие задачи");
    auto* showHighPriorityAction = managementMenu->addAction("Важные задачи");

    managementButton->setMenu(managementMenu);

    connect(addButton, &QPushButton::clicked, this, &ControlPanel::addTaskClicked);
    connect(allTasksButton, &QPushButton::clicked, this, &ControlPanel::showAllTasksClicked);
    connect(saveButton, &QPushButton::clicked, this, &ControlPanel::saveClicked);
    connect(loadButton, &QPushButton::clicked, this, &ControlPanel::loadClicked);

    connect(sortDateAction, &QAction::triggered, this, &ControlPanel::sortByDateClicked);
    connect(sortPriorityAction, &QAction::triggered, this, &ControlPanel::sortByPriorityClicked);
    connect(showCompletedAction, &QAction::triggered, this, &ControlPanel::showCompletedClicked);
    connect(showPendingAction, &QAction::triggered, this, &ControlPanel::showPendingClicked);
    connect(showHighPriorityAction, &QAction::triggered, this, &ControlPanel::showHighPriorityClicked);
}
