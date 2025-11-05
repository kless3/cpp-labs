// WorkoutDialog.h
#ifndef WORKOUTDIALOG_H
#define WORKOUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include "TrainingDiary.h"

class WorkoutDialog : public QDialog
{
Q_OBJECT

public:
    WorkoutDialog(const QString& date, const Workout& workout = Workout(), QWidget* parent = nullptr);
    Workout getWorkout() const;

private slots:
    void addExercise();
    void removeExercise();
    void updateExerciseButtons();

private:
    void setupUI();
    void loadWorkoutData(const Workout& workout);

    QString date;
    Workout workout;

    QLineEdit* typeEdit;
    QListWidget* exercisesList;
    QLineEdit* nameEdit;
    QLineEdit* setsEdit;
    QLineEdit* repsEdit;
    QLineEdit* weightEdit;
    QPushButton* addExerciseBtn;
    QPushButton* removeExerciseBtn;
};

#endif