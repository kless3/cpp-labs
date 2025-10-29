#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QLabel>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include "TrainingDiary.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addExercise();
    void addWorkout();
    void showAllWorkouts();
    void showWeightProgress();
    void showTotalVolume();
    void findWorkoutsByType();
    void showLastWorkout();
    void findWorkoutsByDate();
    void findWorkoutsByPeriod();
    void loadData();

private:
    void setupUI();

    TrainingDiary diary;

    QTabWidget *tabWidget;

    QLineEdit *workoutTypeEdit;
    QDateEdit *workoutDateEdit;
    QListWidget *exercisesList;
    QLineEdit *exerciseNameEdit;
    QLineEdit *exerciseSetsEdit;
    QLineEdit *exerciseRepsEdit;
    QLineEdit *exerciseWeightEdit;
    QTextEdit *resultsText;

    QListWidget *workoutsList;

    QLineEdit *searchTypeEdit;
    QLineEdit *searchExerciseEdit;
    QDateEdit *searchDateEdit;
    QDateEdit *searchStartDateEdit;
    QDateEdit *searchEndDateEdit;
};

#endif