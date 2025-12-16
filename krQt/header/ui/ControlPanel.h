#pragma once

#include <QWidget>

class QPushButton;
class QToolButton;

class ControlPanel : public QWidget {
    Q_OBJECT

public:
    explicit ControlPanel(QWidget* parent = nullptr);

signals:
    void addTaskClicked();
    void showAllTasksClicked();
    void saveClicked();
    void loadClicked();
    void sortByDateClicked();
    void sortByPriorityClicked();
    void showCompletedClicked();
    void showPendingClicked();
    void showHighPriorityClicked();

private:
    void setupUI();

    QPushButton* addButton;
    QToolButton* managementButton;
    QPushButton* allTasksButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
};
