#pragma once

#include "service/TaskManager.h"

#include <QDialog>

class QListWidget;
class QLineEdit;

class AllTasksWindow : public QDialog {
    Q_OBJECT

public:
    explicit AllTasksWindow(TaskManager* taskManager, QWidget* parent = nullptr);

    void showCompleted();

public slots:
    void showAllTasks();
    void sortByDate();
    void sortByPriority();
    void showPending();
    void showHighPriority();
    void onSearchTextChanged(const QString& text);

private:
    void displayTasks(const std::vector<Task>& tasks);
    void setupUI() const;

    TaskManager* taskManager;
    QListWidget* tasksList{nullptr};
    QLineEdit* searchEdit{nullptr};
};
