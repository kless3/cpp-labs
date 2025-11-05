// ProgramDialog.cpp
#include "ProgramDialog.h"
#include <QMessageBox>
#include <QLabel>
#include <QGroupBox>
#include <QDate>
ProgramDialog::ProgramDialog(TrainingDiary* diary, QWidget* parent)
        : QDialog(parent), trainingDiary(diary)
{
    setWindowTitle("🏋️ Управление программами тренировок");
    setMinimumSize(1200, 900); // Увеличили минимальный размер (было 900, 700)
    setStyleSheet(
            "QDialog { background-color: #f8f9fa; }"
            "QGroupBox {"
            "font-weight: bold;"
            "border: 2px solid #bdc3c7;"
            "border-radius: 8px;"
            "margin-top: 10px;"
            "padding-top: 10px;"
            "}"
            "QGroupBox::title {"
            "subcontrol-origin: margin;"
            "left: 10px;"
            "padding: 0 5px 0 5px;"
            "}"
    );

    setupUI();
    loadProgramData();
}

void ProgramDialog::setupUI() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20); // Увеличили отступы
    mainLayout->setSpacing(20); // Увеличили расстояние между панелями

    // Left panel - Programs list
    QWidget* leftPanel = new QWidget();
    leftPanel->setFixedWidth(400); // Увеличили ширину левой панели (было 300)
    QVBoxLayout* leftLayout = new QVBoxLayout(leftPanel);
    leftLayout->setContentsMargins(10, 10, 10, 10);
    leftLayout->setSpacing(15);

    QGroupBox* programsGroup = new QGroupBox("📋 Программы тренировок");
    QVBoxLayout* programsLayout = new QVBoxLayout(programsGroup);
    programsLayout->setSpacing(12);

    programsList = new QListWidget();
    programsList->setStyleSheet(
            "QListWidget {"
            "border: 1px solid #bdc3c7;"
            "border-radius: 5px;"
            "background-color: white;"
            "font-size: 14px;" // Увеличили шрифт
            "min-height: 300px;" // Добавили минимальную высоту
            "}"
            "QListWidget::item {"
            "padding: 12px;" // Увеличили padding
            "border-bottom: 1px solid #ecf0f1;"
            "min-height: 25px;" // Добавили минимальную высоту элементов
            "}"
            "QListWidget::item:selected {"
            "background-color: #3498db;"
            "color: white;"
            "}"
    );

    QHBoxLayout* programNameLayout = new QHBoxLayout();
    programNameEdit = new QLineEdit();
    programNameEdit->setPlaceholderText("Название программы");
    programNameEdit->setStyleSheet("QLineEdit { padding: 12px; border-radius: 5px; border: 1px solid #bdc3c7; font-size: 14px; }"); // Увеличили padding и шрифт

    addProgramBtn = new QPushButton("➕ Добавить");
    addProgramBtn->setStyleSheet(
            "QPushButton {"
            "background-color: #27ae60;"
            "color: white;"
            "border: none;"
            "padding: 12px 16px;" // Увеличили padding
            "border-radius: 5px;"
            "font-weight: bold;"
            "font-size: 14px;" // Увеличили шрифт
            "min-width: 100px;" // Добавили минимальную ширину
            "}"
            "QPushButton:hover { background-color: #229954; }"
            "QPushButton:disabled { background-color: #bdc3c7; }"
    );

    programNameLayout->addWidget(programNameEdit);
    programNameLayout->addWidget(addProgramBtn);

    QHBoxLayout* programButtonsLayout = new QHBoxLayout();
    removeProgramBtn = new QPushButton("🗑️ Удалить");
    duplicateProgramBtn = new QPushButton("📋 Дублировать");
    applyToWeekBtn = new QPushButton("💾 Сохранить");

    QString buttonStyle =
            "QPushButton {"
            "background-color: #3498db;"
            "color: white;"
            "border: none;"
            "padding: 12px 16px;" // Увеличили padding
            "border-radius: 5px;"
            "font-weight: bold;"
            "font-size: 13px;" // Увеличили шрифт
            "min-height: 20px;" // Добавили минимальную высоту
            "}"
            "QPushButton:hover { background-color: #2980b9; }"
            "QPushButton:disabled { background-color: #bdc3c7; }";

    removeProgramBtn->setStyleSheet(buttonStyle);
    duplicateProgramBtn->setStyleSheet(buttonStyle);
    applyToWeekBtn->setStyleSheet(buttonStyle);

    programButtonsLayout->addWidget(removeProgramBtn);
    programButtonsLayout->addWidget(duplicateProgramBtn);
    programButtonsLayout->addStretch();
    programButtonsLayout->addWidget(applyToWeekBtn);

    programsLayout->addWidget(programsList);
    programsLayout->addLayout(programNameLayout);
    programsLayout->addLayout(programButtonsLayout);

    leftLayout->addWidget(programsGroup);

    // Right panel - Program details
    QWidget* rightPanel = new QWidget();
    QVBoxLayout* rightLayout = new QVBoxLayout(rightPanel);
    rightLayout->setContentsMargins(10, 10, 10, 10);
    rightLayout->setSpacing(15);

    tabWidget = new QTabWidget();
    tabWidget->setStyleSheet(
            "QTabWidget::pane {"
            "border: 2px solid #bdc3c7;"
            "border-radius: 8px;"
            "background-color: white;"
            "}"
            "QTabWidget::tab-bar {"
            "alignment: center;"
            "}"
            "QTabBar::tab {"
            "background: #ecf0f1;"
            "border: 2px solid #bdc3c7;"
            "border-bottom: none;"
            "border-top-left-radius: 8px;"
            "border-top-right-radius: 8px;"
            "padding: 12px 20px;" // Увеличили padding
            "font-weight: bold;"
            "font-size: 14px;" // Увеличили шрифт
            "min-width: 120px;" // Добавили минимальную ширину
            "}"
            "QTabBar::tab:selected {"
            "background: #3498db;"
            "color: white;"
            "}"
            "QTabBar::tab:hover {"
            "background: #2980b9;"
            "color: white;"
            "}"
    );

    // Schedule tab
    QWidget* scheduleTab = new QWidget();
    QVBoxLayout* scheduleLayout = new QVBoxLayout(scheduleTab);
    scheduleLayout->setContentsMargins(15, 15, 15, 15);
    scheduleLayout->setSpacing(15);

    QGroupBox* scheduleGroup = new QGroupBox("📅 Расписание на неделю");
    QVBoxLayout* scheduleGroupLayout = new QVBoxLayout(scheduleGroup);
    scheduleGroupLayout->setSpacing(10);

    scheduleTable = new QTableWidget();
    scheduleTable->setColumnCount(3);
    scheduleTable->setHorizontalHeaderLabels({"День недели", "Тип тренировки", "Упражнения"});
    scheduleTable->horizontalHeader()->setStretchLastSection(true);
    scheduleTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    scheduleTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    scheduleTable->setStyleSheet(
            "QTableWidget {"
            "border: 1px solid #bdc3c7;"
            "border-radius: 5px;"
            "background-color: white;"
            "gridline-color: #ecf0f1;"
            "font-size: 14px;" // Увеличили шрифт
            "}"
            "QTableWidget::item {"
            "padding: 12px;" // Увеличили padding
            "border-bottom: 1px solid #ecf0f1;"
            "min-height: 25px;" // Добавили минимальную высоту
            "}"
            "QTableWidget::item:selected {"
            "background-color: #3498db;"
            "color: white;"
            "}"
            "QHeaderView::section {"
            "background-color: #34495e;"
            "color: white;"
            "padding: 12px;" // Увеличили padding
            "border: none;"
            "font-weight: bold;"
            "font-size: 14px;" // Увеличили шрифт
            "}"
    );
    scheduleTable->verticalHeader()->setDefaultSectionSize(50); // Увеличили высоту строк

    scheduleGroupLayout->addWidget(scheduleTable);

    // Exercise form
    QGroupBox* exerciseGroup = new QGroupBox("➕ Добавить упражнение к дню");
    QGridLayout* exerciseLayout = new QGridLayout(exerciseGroup);
    exerciseLayout->setVerticalSpacing(12);
    exerciseLayout->setHorizontalSpacing(15);

    // Увеличили шрифты для всех лейблов
    QString labelStyle = "QLabel { font-size: 14px; font-weight: bold; }";

    exerciseLayout->addWidget(new QLabel("День недели:"), 0, 0);
    dayOfWeekCombo = new QComboBox();
    dayOfWeekCombo->addItems({"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"});
    dayOfWeekCombo->setStyleSheet("QComboBox { padding: 10px; font-size: 14px; min-height: 25px; }"); // Увеличили padding и шрифт
    exerciseLayout->addWidget(dayOfWeekCombo, 0, 1);

    QLabel* exerciseLabel = new QLabel("Упражнение:");
    exerciseLabel->setStyleSheet(labelStyle);
    exerciseLayout->addWidget(exerciseLabel, 1, 0);
    exerciseNameEdit = new QLineEdit();
    exerciseNameEdit->setPlaceholderText("Название упражнения");
    exerciseNameEdit->setStyleSheet("QLineEdit { padding: 10px; font-size: 14px; min-height: 25px; }"); // Увеличили padding и шрифт
    exerciseLayout->addWidget(exerciseNameEdit, 1, 1);

    QLabel* setsLabel = new QLabel("Подходы:");
    setsLabel->setStyleSheet(labelStyle);
    exerciseLayout->addWidget(setsLabel, 2, 0);
    setsSpinBox = new QSpinBox();
    setsSpinBox->setRange(1, 10);
    setsSpinBox->setValue(3);
    setsSpinBox->setStyleSheet("QSpinBox { padding: 10px; font-size: 14px; min-height: 25px; }"); // Увеличили padding и шрифт
    exerciseLayout->addWidget(setsSpinBox, 2, 1);

    QLabel* repsLabel = new QLabel("Повторения:");
    repsLabel->setStyleSheet(labelStyle);
    exerciseLayout->addWidget(repsLabel, 3, 0);
    repsSpinBox = new QSpinBox();
    repsSpinBox->setRange(1, 20);
    repsSpinBox->setValue(10);
    repsSpinBox->setStyleSheet("QSpinBox { padding: 10px; font-size: 14px; min-height: 25px; }"); // Увеличили padding и шрифт
    exerciseLayout->addWidget(repsSpinBox, 3, 1);

    QLabel* weightLabel = new QLabel("Вес (кг):");
    weightLabel->setStyleSheet(labelStyle);
    exerciseLayout->addWidget(weightLabel, 4, 0);
    weightSpinBox = new QDoubleSpinBox();
    weightSpinBox->setRange(0, 200);
    weightSpinBox->setValue(20);
    weightSpinBox->setDecimals(1);
    weightSpinBox->setStyleSheet("QDoubleSpinBox { padding: 10px; font-size: 14px; min-height: 25px; }"); // Увеличили padding и шрифт
    exerciseLayout->addWidget(weightSpinBox, 4, 1);

    QHBoxLayout* exerciseButtonsLayout = new QHBoxLayout();
    addExerciseBtn = new QPushButton("➕ Добавить упражнение");
    removeExerciseBtn = new QPushButton("🗑️ Удалить выбранное");

    QString exerciseButtonStyle =
            "QPushButton {"
            "background-color: #3498db;"
            "color: white;"
            "border: none;"
            "padding: 12px 16px;" // Увеличили padding
            "border-radius: 5px;"
            "font-weight: bold;"
            "font-size: 14px;" // Увеличили шрифт
            "min-height: 25px;" // Добавили минимальную высоту
            "}"
            "QPushButton:hover { background-color: #2980b9; }"
            "QPushButton:disabled { background-color: #bdc3c7; }";

    addExerciseBtn->setStyleSheet(exerciseButtonStyle);
    removeExerciseBtn->setStyleSheet(exerciseButtonStyle);

    exerciseButtonsLayout->addWidget(addExerciseBtn);
    exerciseButtonsLayout->addWidget(removeExerciseBtn);
    exerciseLayout->addLayout(exerciseButtonsLayout, 5, 0, 1, 2);

    // Exercises list for selected day
    QLabel* dayExercisesLabel = new QLabel("Упражнения для выбранного дня:");
    dayExercisesLabel->setStyleSheet("QLabel { font-size: 14px; font-weight: bold; color: #2c3e50; }");
    exerciseLayout->addWidget(dayExercisesLabel, 6, 0, 1, 2);

    dayExercisesList = new QListWidget();
    dayExercisesList->setMaximumHeight(200); // Увеличили высоту списка упражнений
    dayExercisesList->setStyleSheet(
            "QListWidget {"
            "border: 1px solid #bdc3c7;"
            "border-radius: 5px;"
            "background-color: white;"
            "font-size: 13px;" // Увеличили шрифт
            "}"
            "QListWidget::item {"
            "padding: 10px;" // Увеличили padding
            "border-bottom: 1px solid #ecf0f1;"
            "min-height: 20px;" // Добавили минимальную высоту
            "}"
            "QListWidget::item:selected {"
            "background-color: #3498db;"
            "color: white;"
            "}"
    );
    exerciseLayout->addWidget(dayExercisesList, 7, 0, 1, 2);

    scheduleLayout->addWidget(scheduleGroup);
    scheduleLayout->addWidget(exerciseGroup);

    tabWidget->addTab(scheduleTab, "📅 Расписание");

    rightLayout->addWidget(tabWidget);

    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(rightPanel);

    // Connections
    connect(programsList, &QListWidget::currentRowChanged, this, &ProgramDialog::onProgramSelectionChanged);
    connect(addProgramBtn, &QPushButton::clicked, this, &ProgramDialog::onAddProgram);
    connect(removeProgramBtn, &QPushButton::clicked, this, &ProgramDialog::onRemoveProgram);
    connect(duplicateProgramBtn, &QPushButton::clicked, this, &ProgramDialog::onDuplicateProgram);
    connect(applyToWeekBtn, &QPushButton::clicked, this, &ProgramDialog::onApplyToWeek);
    connect(programNameEdit, &QLineEdit::textChanged, this, &ProgramDialog::onProgramNameChanged);
    connect(addExerciseBtn, &QPushButton::clicked, this, &ProgramDialog::onAddExerciseToDay);
    connect(removeExerciseBtn, &QPushButton::clicked, this, &ProgramDialog::onRemoveExerciseFromDay);
    connect(dayOfWeekCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ProgramDialog::onDaySelectionChanged);

    onProgramSelectionChanged();
    onDaySelectionChanged();
}

void ProgramDialog::loadProgramData() {
    updateProgramList();
}

void ProgramDialog::updateProgramList() {
    programsList->clear();
    for (const auto& program : trainingDiary->getAllPrograms()) {
        programsList->addItem(QString::fromStdString(program.getName()));
    }

    if (programsList->count() > 0) {
        programsList->setCurrentRow(trainingDiary->getCurrentProgramIndex());
    }
}

void ProgramDialog::onProgramSelectionChanged() {
    int currentRow = programsList->currentRow();
    bool hasSelection = currentRow >= 0;

    removeProgramBtn->setEnabled(hasSelection && programsList->count() > 1);
    duplicateProgramBtn->setEnabled(hasSelection);
    applyToWeekBtn->setEnabled(hasSelection);

    if (hasSelection) {
        trainingDiary->setCurrentProgram(currentRow);
        updateDayScheduleTable();
    }
}

void ProgramDialog::onAddProgram() {
    QString name = programNameEdit->text().trimmed();
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название программы!");
        return;
    }

    trainingDiary->createProgram(name.toStdString());
    updateProgramList();
    programNameEdit->clear();

    // Select the new program
    programsList->setCurrentRow(programsList->count() - 1);
}

void ProgramDialog::onRemoveProgram() {
    int currentRow = programsList->currentRow();
    if (currentRow >= 0 && programsList->count() > 1) {
        QMessageBox::StandardButton reply = QMessageBox::question(
                this,
                "Удаление программы",
                QString("Удалить программу \"%1\"?").arg(programsList->currentItem()->text()),
                QMessageBox::Yes | QMessageBox::No
        );

        if (reply == QMessageBox::Yes) {
            trainingDiary->removeProgram(currentRow);
            updateProgramList();
        }
    }
}

void ProgramDialog::onDuplicateProgram() {
    int currentRow = programsList->currentRow();
    if (currentRow >= 0) {
        QString originalName = programsList->currentItem()->text();
        QString newName = originalName + " (копия)";

        trainingDiary->duplicateProgram(currentRow, newName.toStdString());
        updateProgramList();

        // Select the new program
        programsList->setCurrentRow(programsList->count() - 1);
    }
}

void ProgramDialog::onProgramNameChanged() {
    addProgramBtn->setEnabled(!programNameEdit->text().trimmed().isEmpty());
}

void ProgramDialog::onApplyToWeek() {
    QMessageBox::information(this, "Успех", "Программа применена к текущей неделе!");
    trainingDiary->applyProgramToWeek(QDate::currentDate().toString("dd.MM.yyyy").toStdString());
    accept();
}

void ProgramDialog::updateDayScheduleTable() {
    scheduleTable->setRowCount(7);

    QStringList dayNames = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};

    for (int i = 0; i < 7; i++) {
        // Правильное преобразование: i=0 -> день недели 1 (Понедельник)
        // i=1 -> день недели 2 (Вторник) и т.д.
        Workout workout = trainingDiary->getWorkoutTemplateForDay(i + 1);

        scheduleTable->setItem(i, 0, new QTableWidgetItem(dayNames[i]));

        if (workout.getType().empty()) {
            scheduleTable->setItem(i, 1, new QTableWidgetItem("—"));
            scheduleTable->setItem(i, 2, new QTableWidgetItem("—"));
        } else {
            scheduleTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(workout.getType())));

            QString exercises;
            for (int j = 0; j < workout.getExerciseCount() && j < 3; j++) {
                Exercise ex = workout.getExercise(j);
                exercises += QString::fromStdString(ex.name);
                if (j < workout.getExerciseCount() - 1 && j < 2) {
                    exercises += ", ";
                }
            }
            if (workout.getExerciseCount() > 3) {
                exercises += QString("... (+%1)").arg(workout.getExerciseCount() - 3);
            }
            scheduleTable->setItem(i, 2, new QTableWidgetItem(exercises));
        }
    }

    scheduleTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    scheduleTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    scheduleTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
}

void ProgramDialog::onDaySelectionChanged() {
    dayExercisesList->clear();

    // Правильное преобразование: currentIndex()=0 -> день недели 1 (Понедельник)
    // currentIndex()=1 -> день недели 2 (Вторник) и т.д.
    int dayOfWeek = dayOfWeekCombo->currentIndex() + 1;
    Workout workout = trainingDiary->getWorkoutTemplateForDay(dayOfWeek);

    for (int i = 0; i < workout.getExerciseCount(); i++) {
        Exercise ex = workout.getExercise(i);
        QString itemText = QString("%1: %2x%3 - %4 кг")
                .arg(QString::fromStdString(ex.name))
                .arg(ex.sets)
                .arg(ex.reps)
                .arg(ex.weight);
        dayExercisesList->addItem(itemText);
    }
}

void ProgramDialog::onAddExerciseToDay() {
    QString name = exerciseNameEdit->text().trimmed();
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название упражнения!");
        return;
    }

    // Правильное преобразование: currentIndex()=0 -> день недели 1 (Понедельник)
    int dayOfWeek = dayOfWeekCombo->currentIndex() + 1;
    Workout currentWorkout = trainingDiary->getWorkoutTemplateForDay(dayOfWeek);

    // If no workout exists for this day, create one
    if (currentWorkout.getType().empty()) {
        QString workoutType = dayOfWeekCombo->currentText() + " тренировка";
        currentWorkout.setType(workoutType.toStdString());
    }

    Exercise newExercise;
    newExercise.name = name.toStdString();
    newExercise.sets = setsSpinBox->value();
    newExercise.reps = repsSpinBox->value();
    newExercise.weight = weightSpinBox->value();

    currentWorkout.addExercise(newExercise);
    trainingDiary->setWorkoutTemplateForDay(dayOfWeek, currentWorkout);

    // Update UI
    updateDayScheduleTable();
    onDaySelectionChanged();
    clearExerciseForm();

    QMessageBox::information(this, "Успех", "Упражнение добавлено к дню!");
}

void ProgramDialog::onRemoveExerciseFromDay() {
    int currentRow = dayExercisesList->currentRow();
    if (currentRow >= 0) {
        // Правильное преобразование: currentIndex()=0 -> день недели 1 (Понедельник)
        int dayOfWeek = dayOfWeekCombo->currentIndex() + 1;
        Workout currentWorkout = trainingDiary->getWorkoutTemplateForDay(dayOfWeek);

        // Create new workout without the removed exercise
        Workout newWorkout;
        newWorkout.setType(currentWorkout.getType());

        for (int i = 0; i < currentWorkout.getExerciseCount(); i++) {
            if (i != currentRow) {
                newWorkout.addExercise(currentWorkout.getExercise(i));
            }
        }

        trainingDiary->setWorkoutTemplateForDay(dayOfWeek, newWorkout);

        // Update UI
        updateDayScheduleTable();
        onDaySelectionChanged();
    }
}

void ProgramDialog::clearExerciseForm() {
    exerciseNameEdit->clear();
    setsSpinBox->setValue(3);
    repsSpinBox->setValue(10);
    weightSpinBox->setValue(20);
}