#pragma once

#include "service/TaskManager.h"
#include "service/NotificationService.h"

#include <QMainWindow>
#include <QLabel>
#include <QDate>

class NavigationHeader;
class TaskListWidget;
class ControlPanel;

class DailyPlannerApp : public QMainWindow {
    Q_OBJECT

public:
    explicit DailyPlannerApp(QWidget* parent = nullptr);
    ~DailyPlannerApp() override;

private slots:
    void addTask();
    void showAllTasksWindow();
    void saveData() const;
    void loadData();
    void nextDay();
    void prevDay();
    void updateDisplay();
    void onTasksUpdated();

private:
    void onSortByDate();
    void onSortByPriority();
    void onShowCompleted();
    void onShowPending();
    void onShowHighPriority();
    void setupUI();
    void applyStyle() const;
    void loadInitialData();

    TaskManager taskManager;
    NotificationService notificationService;
    NavigationHeader* navigationHeader;
    TaskListWidget* todayTasksWidget;
    TaskListWidget* tomorrowTasksWidget;
    ControlPanel* controlPanel;
    QLabel* statusLabel;
    QDate currentDate{QDate::currentDate()};
};
