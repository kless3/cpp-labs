#include "ui/AllTasksWindow.h"
#include "utils/StyleLoader.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>

AllTasksWindow::AllTasksWindow(TaskManager* taskManager, QWidget* parent)
    : QDialog(parent)
    , taskManager(taskManager)
{
    setWindowTitle("Все задачи");
    setMinimumSize(900, 650);

    QString styleSheet = StyleLoader::loadStyleSheet("resources/styles/all_tasks_window.qss");
    setStyleSheet(styleSheet);

    auto* layout = new QVBoxLayout(this);

    auto* headerLabel = new QLabel("Все задачи");
    headerLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin: 10px;");

    auto* filterLayout = new QHBoxLayout();
    searchEdit = new QLineEdit();
    searchEdit->setPlaceholderText("Поиск задач...");
    searchEdit->setStyleSheet(
        "background: white; border: 1px solid #ccc; border-radius: 4px; padding: 6px;"
    );

    auto* filterButton = new QPushButton("Все");
    connect(filterButton, &QPushButton::clicked, this, &AllTasksWindow::showAllTasks);

    auto* completedButton = new QPushButton("Выполненные");
    connect(completedButton, &QPushButton::clicked, this, &AllTasksWindow::showCompleted);

    auto* pendingButton = new QPushButton("Ожидающие");
    connect(pendingButton, &QPushButton::clicked, this, &AllTasksWindow::showPending);

    auto* highPriorityButton = new QPushButton("Высокий приоритет");
    connect(highPriorityButton, &QPushButton::clicked, this, &AllTasksWindow::showHighPriority);

    filterLayout->addWidget(searchEdit);
    filterLayout->addWidget(filterButton);
    filterLayout->addWidget(completedButton);
    filterLayout->addWidget(pendingButton);
    filterLayout->addWidget(highPriorityButton);

    auto* sortLayout = new QHBoxLayout();
    auto* sortByDateButton = new QPushButton("Сортировать по дате");
    connect(sortByDateButton, &QPushButton::clicked, this, &AllTasksWindow::sortByDate);

    auto* sortByPriorityButton = new QPushButton("Сортировать по приоритету");
    connect(sortByPriorityButton, &QPushButton::clicked, this, &AllTasksWindow::sortByPriority);

    sortLayout->addWidget(sortByDateButton);
    sortLayout->addWidget(sortByPriorityButton);

    tasksList = new QListWidget();

    layout->addWidget(headerLabel);
    layout->addLayout(filterLayout);
    layout->addLayout(sortLayout);
    layout->addWidget(tasksList);

    connect(searchEdit, &QLineEdit::textChanged, this, &AllTasksWindow::onSearchTextChanged);

    showAllTasks();
}

void AllTasksWindow::showAllTasks() {
    displayTasks(taskManager->getAllTasks());
}

void AllTasksWindow::showCompleted() {
    displayTasks(taskManager->getCompleted());
}

void AllTasksWindow::showPending() {
    displayTasks(taskManager->getPending());
}

void AllTasksWindow::showHighPriority() {
    displayTasks(taskManager->getHighPriority());
}

void AllTasksWindow::sortByDate() {
    taskManager->sortByDate();
    showAllTasks();
}

void AllTasksWindow::sortByPriority() {
    taskManager->sortByPriority();
    showAllTasks();
}

void AllTasksWindow::onSearchTextChanged(const QString& text) {
    if (text.isEmpty()) {
        showAllTasks();
    } else {
        displayTasks(taskManager->searchByDescription(text.toStdString()));
    }
}

void AllTasksWindow::displayTasks(const std::vector<Task>& tasks) {
    tasksList->clear();

    for (const auto& task : tasks) {
        QString taskInfo = QString("%1 | %2 | %3 | %4 | %5")
                               .arg(task.getId())
                               .arg(QString::fromStdString(task.getDescription()))
                               .arg(QString::fromStdString(task.getDate()))
                               .arg(QString::fromStdString(task.getTime()))
                               .arg(task.getPriorityText());

        if (task.isCompleted()) {
            taskInfo += " [Выполнено]";
        }

        tasksList->addItem(taskInfo);
    }
}

void AllTasksWindow::setupUI() {
}
