#include "application/DailyPlannerApp.h"
#include "ui/NavigationHeader.h"
#include "ui/TaskListWidget.h"
#include "ui/ControlPanel.h"
#include "ui/AddTaskDialog.h"
#include "ui/AllTasksWindow.h"
#include "service/DateService.h"
#include "utils/StyleLoader.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFile>

DailyPlannerApp::DailyPlannerApp(QWidget* parent)
    : QMainWindow(parent)
{
    setupUI();
    applyStyle();
    loadInitialData();

    connect(&notificationService, &NotificationService::upcomingTaskDetected,
            this, [this](const QString& message) {
                statusLabel->setText(message);
            });

    connect(controlPanel, &ControlPanel::sortByDateClicked,
            this, &DailyPlannerApp::onSortByDate);
    connect(controlPanel, &ControlPanel::sortByPriorityClicked,
            this, &DailyPlannerApp::onSortByPriority);
    connect(controlPanel, &ControlPanel::showCompletedClicked,
            this, &DailyPlannerApp::onShowCompleted);
    connect(controlPanel, &ControlPanel::showPendingClicked,
            this, &DailyPlannerApp::onShowPending);
    connect(controlPanel, &ControlPanel::showHighPriorityClicked,
            this, &DailyPlannerApp::onShowHighPriority);
}

DailyPlannerApp::~DailyPlannerApp() {
    taskManager.saveToFile("tasks.txt");
}

void DailyPlannerApp::onSortByDate() {
    taskManager.sortByDate();
    updateDisplay();
    statusLabel->setText("Отсортировано по дате");
}

void DailyPlannerApp::onSortByPriority() {
    taskManager.sortByPriority();
    updateDisplay();
    statusLabel->setText("Отсортировано по приоритету");
}

void DailyPlannerApp::onShowCompleted() {
    auto* window = new AllTasksWindow(&taskManager, this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->showCompleted();
    window->exec();
}

void DailyPlannerApp::onShowPending() {
    auto* window = new AllTasksWindow(&taskManager, this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->showPending();
    window->exec();
}

void DailyPlannerApp::onShowHighPriority() {
    auto* window = new AllTasksWindow(&taskManager, this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->showHighPriority();
    window->exec();
}

void DailyPlannerApp::setupUI() {
    setWindowTitle("Ежедневник");
    setMinimumSize(1200, 800);

    auto* centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    auto* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(15, 15, 15, 15);

    navigationHeader = new NavigationHeader();
    mainLayout->addWidget(navigationHeader);

    auto* tasksLayout = new QHBoxLayout();
    tasksLayout->setSpacing(20);

    todayTasksWidget = new TaskListWidget("", &taskManager);
    tomorrowTasksWidget = new TaskListWidget("", &taskManager);

    tasksLayout->addWidget(todayTasksWidget, 1);
    tasksLayout->addWidget(tomorrowTasksWidget, 1);

    mainLayout->addLayout(tasksLayout, 1);

    controlPanel = new ControlPanel();
    mainLayout->addWidget(controlPanel);

    statusLabel = new QLabel("Всего задач: 0");
    statusLabel->setStyleSheet("font-size: 12px; color: #666;");
    mainLayout->addWidget(statusLabel);

    connect(navigationHeader, &NavigationHeader::previousDay,
            this, &DailyPlannerApp::prevDay);
    connect(navigationHeader, &NavigationHeader::nextDay,
            this, &DailyPlannerApp::nextDay);

    connect(controlPanel, &ControlPanel::addTaskClicked,
            this, &DailyPlannerApp::addTask);
    connect(controlPanel, &ControlPanel::showAllTasksClicked,
            this, &DailyPlannerApp::showAllTasksWindow);
    connect(controlPanel, &ControlPanel::saveClicked,
            this, &DailyPlannerApp::saveData);
    connect(controlPanel, &ControlPanel::loadClicked,
            this, &DailyPlannerApp::loadData);

    connect(todayTasksWidget, &TaskListWidget::tasksUpdated,
            this, &DailyPlannerApp::onTasksUpdated);
    connect(tomorrowTasksWidget, &TaskListWidget::tasksUpdated,
            this, &DailyPlannerApp::onTasksUpdated);

    updateDisplay();
}

void DailyPlannerApp::applyStyle() const {
    QString styleSheet = StyleLoader::loadStyleSheet("resources/styles/main.qss");
    centralWidget()->setStyleSheet(styleSheet);
}

void DailyPlannerApp::loadInitialData() {
    QFile file("tasks.txt");
    if (file.exists()) {
        taskManager.loadFromFile("tasks.txt");
    } else {
        taskManager.addTask("Сделать курсач по C++", "2024-12-20", "14:00", 5);
        taskManager.addTask("Купить продукты",
                            QDate::currentDate().toString("yyyy-MM-dd").toStdString(),
                            "10:00", 3);
        taskManager.addTask("Сходить в спортзал",
                            QDate::currentDate().toString("yyyy-MM-dd").toStdString(),
                            "18:00", 4);
    }
}

void DailyPlannerApp::addTask() {
    AddTaskDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString description = dialog.getDescription();
        if (description.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Введите описание задачи!");
            return;
        }

        taskManager.addTask(
            description.toStdString(),
            dialog.getDate().toStdString(),
            dialog.getTime().toStdString(),
            dialog.getPriority()
        );
        updateDisplay();
    }
}

void DailyPlannerApp::showAllTasksWindow() {
    auto* window = new AllTasksWindow(&taskManager, this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->exec();
}

void DailyPlannerApp::saveData() const {
    taskManager.saveToFile("tasks.txt");
    QMessageBox::information(nullptr, "Успех", "Задачи сохранены в tasks.txt");
}

void DailyPlannerApp::loadData() {
    taskManager.loadFromFile("tasks.txt");
    updateDisplay();
    QMessageBox::information(this, "Успех", "Задачи загружены из tasks.txt");
}

void DailyPlannerApp::nextDay() {
    currentDate = currentDate.addDays(1);
    updateDisplay();
}

void DailyPlannerApp::prevDay() {
    currentDate = currentDate.addDays(-1);
    updateDisplay();
}

void DailyPlannerApp::updateDisplay() {
    navigationHeader->setDate(currentDate);

    QDate today = QDate::currentDate();
    QDate tomorrow = today.addDays(1);

    if (currentDate == today) {
        todayTasksWidget->setTitle("СЕГОДНЯ");
    } else {
        todayTasksWidget->setTitle(DateService::formatDate(currentDate));
    }

    if (currentDate.addDays(1) == tomorrow) {
        tomorrowTasksWidget->setTitle("ЗАВТРА");
    } else {
        tomorrowTasksWidget->setTitle(DateService::formatDate(currentDate.addDays(1)));
    }

    todayTasksWidget->displayTasksForDate(currentDate.toString("yyyy-MM-dd"));
    tomorrowTasksWidget->displayTasksForDate(currentDate.addDays(1).toString("yyyy-MM-dd"));

    statusLabel->setText(QString("Всего задач: %1").arg(taskManager.getAllTasks().size()));

    notificationService.checkUpcomingTasks(taskManager.getAllTasks());
}

void DailyPlannerApp::onTasksUpdated() {
    updateDisplay();
}
