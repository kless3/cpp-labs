// WorkoutDialog.cpp
#include "WorkoutDialog.h"
#include <QMessageBox>
#include <QLabel>

WorkoutDialog::WorkoutDialog(const QString& date, const Workout& workout, QWidget* parent)
        : QDialog(parent), date(date), workout(workout)
{
    setupUI();
    loadWorkoutData(workout);
    setWindowTitle("Тренировка на " + date);
}

void WorkoutDialog::setupUI() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QFormLayout* formLayout = new QFormLayout();

    typeEdit = new QLineEdit();
    formLayout->addRow("Тип тренировки:", typeEdit);

    mainLayout->addLayout(formLayout);

    // Exercises section
    mainLayout->addWidget(new QLabel("Упражнения:"));

    exercisesList = new QListWidget();
    mainLayout->addWidget(exercisesList);

    QHBoxLayout* exerciseFormLayout = new QHBoxLayout();

    nameEdit = new QLineEdit();
    nameEdit->setPlaceholderText("Название");
    setsEdit = new QLineEdit();
    setsEdit->setPlaceholderText("Подходы");
    repsEdit = new QLineEdit();
    repsEdit->setPlaceholderText("Повторения");
    weightEdit = new QLineEdit();
    weightEdit->setPlaceholderText("Вес (кг)");

    exerciseFormLayout->addWidget(nameEdit);
    exerciseFormLayout->addWidget(setsEdit);
    exerciseFormLayout->addWidget(repsEdit);
    exerciseFormLayout->addWidget(weightEdit);

    mainLayout->addLayout(exerciseFormLayout);

    QHBoxLayout* exerciseButtonsLayout = new QHBoxLayout();

    addExerciseBtn = new QPushButton("Добавить упражнение");
    removeExerciseBtn = new QPushButton("Удалить упражнение");

    exerciseButtonsLayout->addWidget(addExerciseBtn);
    exerciseButtonsLayout->addWidget(removeExerciseBtn);

    mainLayout->addLayout(exerciseButtonsLayout);

    // Dialog buttons
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    mainLayout->addWidget(buttonBox);

    connect(addExerciseBtn, &QPushButton::clicked, this, &WorkoutDialog::addExercise);
    connect(removeExerciseBtn, &QPushButton::clicked, this, &WorkoutDialog::removeExercise);
    connect(exercisesList, &QListWidget::itemSelectionChanged, this, &WorkoutDialog::updateExerciseButtons);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    updateExerciseButtons();
}

void WorkoutDialog::loadWorkoutData(const Workout& workout) {
    typeEdit->setText(QString::fromStdString(workout.getType()));

    for (int i = 0; i < workout.getExerciseCount(); i++) {
        Exercise ex = workout.getExercise(i);
        QString itemText = QString("%1 | %2x%3 | %4 кг")
                .arg(QString::fromStdString(ex.name))
                .arg(ex.sets)
                .arg(ex.reps)
                .arg(ex.weight);
        exercisesList->addItem(itemText);
    }
}

Workout WorkoutDialog::getWorkout() const {
    Workout result(date.toStdString(), typeEdit->text().toStdString());

    for (int i = 0; i < exercisesList->count(); i++) {
        // In a real implementation, you would parse the exercise data back from the list
        // For simplicity, we're just returning the original exercises
        if (i < workout.getExerciseCount()) {
            result.addExercise(workout.getExercise(i));
        }
    }

    return result;
}

void WorkoutDialog::addExercise() {
    QString name = nameEdit->text();
    QString setsStr = setsEdit->text();
    QString repsStr = repsEdit->text();
    QString weightStr = weightEdit->text();

    if (name.isEmpty() || setsStr.isEmpty() || repsStr.isEmpty() || weightStr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все поля упражнения!");
        return;
    }

    bool setsOk, repsOk, weightOk;
    int sets = setsStr.toInt(&setsOk);
    int reps = repsStr.toInt(&repsOk);
    double weight = weightStr.toDouble(&weightOk);

    if (!setsOk || !repsOk || !weightOk) {
        QMessageBox::warning(this, "Ошибка", "Проверьте правильность числовых значений!");
        return;
    }

    Exercise ex;
    ex.name = name.toStdString();
    ex.sets = sets;
    ex.reps = reps;
    ex.weight = weight;
    workout.addExercise(ex);

    QString itemText = QString("%1 | %2x%3 | %4 кг")
            .arg(name)
            .arg(sets)
            .arg(reps)
            .arg(weight);
    exercisesList->addItem(itemText);

    nameEdit->clear();
    setsEdit->clear();
    repsEdit->clear();
    weightEdit->clear();
}

void WorkoutDialog::removeExercise() {
    int currentRow = exercisesList->currentRow();
    if (currentRow >= 0) {
        delete exercisesList->takeItem(currentRow);
        // Also remove from workout (simplified)
    }
}

void WorkoutDialog::updateExerciseButtons() {
    removeExerciseBtn->setEnabled(exercisesList->currentRow() >= 0);
}