#ifndef PROGRAMDIALOG_H
#define PROGRAMDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QTableWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QHeaderView>
#include "TrainingDiary.h"

class ProgramDialog : public QDialog
{
Q_OBJECT

public:
    ProgramDialog(TrainingDiary* diary, QWidget* parent = nullptr);
    void loadProgramData();

private slots:
    void onProgramSelectionChanged();
    void onAddProgram();
    void onRemoveProgram();
    void onDuplicateProgram();
    void onProgramNameChanged();
    void onApplyToWeek();
    void onAddExerciseToDay();
    void onRemoveExerciseFromDay();
    void onDaySelectionChanged();

private:
    void setupUI();
    void updateProgramList();
    void updateDayScheduleTable();
    void clearExerciseForm();

    TrainingDiary* trainingDiary;

    QListWidget* programsList;
    QLineEdit* programNameEdit;
    QPushButton* addProgramBtn;
    QPushButton* removeProgramBtn;
    QPushButton* duplicateProgramBtn;
    QPushButton* applyToWeekBtn;

    QTabWidget* tabWidget;
    QTableWidget* scheduleTable;

    // Exercise form
    QLineEdit* exerciseNameEdit;
    QSpinBox* setsSpinBox;
    QSpinBox* repsSpinBox;
    QDoubleSpinBox* weightSpinBox;
    QComboBox* dayOfWeekCombo;
    QPushButton* addExerciseBtn;
    QPushButton* removeExerciseBtn;

    QListWidget* dayExercisesList;
};

#endif