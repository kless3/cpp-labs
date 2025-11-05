// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QStatusBar>
#include "TrainingDiary.h"
#include "CalendarWidget.h"
#include "WorkoutDialog.h"
#include "ProgramDialog.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private slots:
    void showWorkoutDialog(const QString& date, const Workout& workout = Workout());
    void managePrograms();
    void updateProgramComboBox();
    void onProgramChanged(int index);

private:
    void setupUI();
    void setupMenu();

    TrainingDiary* trainingDiary;
    CalendarWidget* calendarWidget;
    QComboBox* programComboBox;
};

#endif