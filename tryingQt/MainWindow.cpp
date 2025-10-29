#include "MainWindow.h"
#include <QMessageBox>
#include <QGroupBox>
#include <vector>

struct TempExercise {
    QString name;
    int sets;
    int reps;
    double weight;
};

std::vector<TempExercise> tempExercises;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    setupUI();
    loadData();
    setWindowTitle("Дневник Тренировок");
    resize(800, 600);
}

void MainWindow::setupUI()
{
    tabWidget = new QTabWidget(this);
    setCentralWidget(tabWidget);

    auto *addTab = new QWidget();
    auto *addLayout = new QVBoxLayout(addTab);

    auto *workoutGroup = new QGroupBox("Данные тренировки");
    auto *workoutForm = new QFormLayout(workoutGroup);

    workoutDateEdit = new QDateEdit(QDate::currentDate());
    workoutDateEdit->setDisplayFormat("dd.MM.yyyy");
    workoutTypeEdit = new QLineEdit();

    workoutForm->addRow("Дата:", workoutDateEdit);
    workoutForm->addRow("Тип тренировки:", workoutTypeEdit);

    auto *exerciseGroup = new QGroupBox("Добавить упражнение");
    auto *exerciseForm = new QFormLayout(exerciseGroup);

    exerciseNameEdit = new QLineEdit();
    exerciseSetsEdit = new QLineEdit();
    exerciseRepsEdit = new QLineEdit();
    exerciseWeightEdit = new QLineEdit();

    exerciseForm->addRow("Название:", exerciseNameEdit);
    exerciseForm->addRow("Подходы:", exerciseSetsEdit);
    exerciseForm->addRow("Повторения:", exerciseRepsEdit);
    exerciseForm->addRow("Вес (кг):", exerciseWeightEdit);

    auto *addExerciseBtn = new QPushButton("Добавить упражнение");
    auto *addWorkoutBtn = new QPushButton("Сохранить тренировку");

    exercisesList = new QListWidget();

    auto *viewTab = new QWidget();
    auto *viewLayout = new QVBoxLayout(viewTab);

    auto *showAllBtn = new QPushButton("Показать все тренировки");
    auto *showLastBtn = new QPushButton("Последняя тренировка");
    auto *showVolumeBtn = new QPushButton("Общий тоннаж");

    workoutsList = new QListWidget();

    auto *searchTab = new QWidget();
    auto *searchLayout = new QVBoxLayout(searchTab);

    auto *searchGroup = new QGroupBox("Поиск тренировок");
    auto *searchForm = new QFormLayout(searchGroup);

    searchTypeEdit = new QLineEdit();
    searchExerciseEdit = new QLineEdit();
    searchDateEdit = new QDateEdit(QDate::currentDate());
    searchDateEdit->setDisplayFormat("dd.MM.yyyy");
    searchStartDateEdit = new QDateEdit(QDate::currentDate().addDays(-7));
    searchStartDateEdit->setDisplayFormat("dd.MM.yyyy");
    searchEndDateEdit = new QDateEdit(QDate::currentDate());
    searchEndDateEdit->setDisplayFormat("dd.MM.yyyy");

    searchForm->addRow("По типу:", searchTypeEdit);
    searchForm->addRow("По упражнению:", searchExerciseEdit);
    searchForm->addRow("По дате:", searchDateEdit);
    searchForm->addRow("Начальная дата:", searchStartDateEdit);
    searchForm->addRow("Конечная дата:", searchEndDateEdit);

    auto *searchTypeBtn = new QPushButton("Найти по типу");
    auto *searchProgressBtn = new QPushButton("Анализ прогресса");
    auto *searchDateBtn = new QPushButton("Найти по дате");
    auto *searchPeriodBtn = new QPushButton("Найти за период");

    resultsText = new QTextEdit();
    resultsText->setReadOnly(true);

    addLayout->addWidget(workoutGroup);
    addLayout->addWidget(exerciseGroup);
    addLayout->addWidget(addExerciseBtn);
    addLayout->addWidget(new QLabel("Добавленные упражнения:"));
    addLayout->addWidget(exercisesList);
    addLayout->addWidget(addWorkoutBtn);

    viewLayout->addWidget(showAllBtn);
    viewLayout->addWidget(showLastBtn);
    viewLayout->addWidget(showVolumeBtn);
    viewLayout->addWidget(workoutsList);

    searchLayout->addWidget(searchGroup);
    searchLayout->addWidget(searchTypeBtn);
    searchLayout->addWidget(searchProgressBtn);
    searchLayout->addWidget(searchDateBtn);
    searchLayout->addWidget(searchPeriodBtn);
    searchLayout->addWidget(new QLabel("Результаты:"));
    searchLayout->addWidget(resultsText);

    tabWidget->addTab(addTab, "Добавить тренировку");
    tabWidget->addTab(viewTab, "Просмотр и анализ");
    tabWidget->addTab(searchTab, "Поиск");

    connect(addExerciseBtn, &QPushButton::clicked, this, &MainWindow::addExercise);
    connect(addWorkoutBtn, &QPushButton::clicked, this, &MainWindow::addWorkout);
    connect(showAllBtn, &QPushButton::clicked, this, &MainWindow::showAllWorkouts);
    connect(showLastBtn, &QPushButton::clicked, this, &MainWindow::showLastWorkout);
    connect(showVolumeBtn, &QPushButton::clicked, this, &MainWindow::showTotalVolume);
    connect(searchTypeBtn, &QPushButton::clicked, this, &MainWindow::findWorkoutsByType);
    connect(searchProgressBtn, &QPushButton::clicked, this, &MainWindow::showWeightProgress);
    connect(searchDateBtn, &QPushButton::clicked, this, &MainWindow::findWorkoutsByDate);
    connect(searchPeriodBtn, &QPushButton::clicked, this, &MainWindow::findWorkoutsByPeriod);
}

void MainWindow::addExercise()
{
    QString name = exerciseNameEdit->text();
    QString setsStr = exerciseSetsEdit->text();
    QString repsStr = exerciseRepsEdit->text();
    QString weightStr = exerciseWeightEdit->text();

    if(name.isEmpty() || setsStr.isEmpty() || repsStr.isEmpty() || weightStr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все поля упражнения!");
        return;
    }

    bool setsOk, repsOk, weightOk;
    int sets = setsStr.toInt(&setsOk);
    int reps = repsStr.toInt(&repsOk);
    double weight = weightStr.toDouble(&weightOk);

    if(!setsOk || !repsOk || !weightOk) {
        QMessageBox::warning(this, "Ошибка", "Проверьте правильность числовых значений!");
        return;
    }

    TempExercise tempEx;
    tempEx.name = name;
    tempEx.sets = sets;
    tempEx.reps = reps;
    tempEx.weight = weight;
    tempExercises.push_back(tempEx);

    QString exerciseStr = QString("%1 | %2x%3 | %4 кг").arg(name).arg(sets).arg(reps).arg(weight);
    exercisesList->addItem(exerciseStr);

    exerciseNameEdit->clear();
    exerciseSetsEdit->clear();
    exerciseRepsEdit->clear();
    exerciseWeightEdit->clear();
}

void MainWindow::addWorkout()
{
    QString type = workoutTypeEdit->text();
    if(type.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите тип тренировки!");
        return;
    }

    if(tempExercises.empty()) {
        QMessageBox::warning(this, "Ошибка", "Добавьте хотя бы одно упражнение!");
        return;
    }

    Workout workout;
    workout.setDate(workoutDateEdit->date().toString("dd.MM.yyyy").toStdString());
    workout.setType(type.toStdString());

    for(const auto& tempEx : tempExercises) {
        Exercise ex;
        ex.name = tempEx.name.toStdString();
        ex.sets = tempEx.sets;
        ex.reps = tempEx.reps;
        ex.weight = tempEx.weight;
        workout.addExercise(ex);
    }

    diary.addWorkout(workout);

    tempExercises.clear();
    exercisesList->clear();
    workoutTypeEdit->clear();
    workoutDateEdit->setDate(QDate::currentDate());

    QMessageBox::information(this, "Успех", "Тренировка успешно сохранена!");
}

void MainWindow::showAllWorkouts()
{
    workoutsList->clear();
    auto workouts = diary.getAllWorkouts();

    if(workouts.empty()) {
        workoutsList->addItem("Нет записей о тренировках");
        return;
    }

    for(const auto& workout : workouts) {
        workoutsList->addItem(QString::fromStdString(workout.toString()));
        workoutsList->addItem(""); // Пустая строка для разделения
    }
}

void MainWindow::showWeightProgress()
{
    QString exerciseName = searchExerciseEdit->text();
    if(exerciseName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название упражнения!");
        return;
    }

    auto progress = diary.getWeightProgress(exerciseName.toStdString());
    resultsText->clear();

    if(progress.empty()) {
        resultsText->setText("Упражнение не найдено!");
        return;
    }

    QString result = "Прогресс в упражнении: " + exerciseName + "\n\n";
    for(const auto& item : progress) {
        result += QString::fromStdString(item) + "\n";
    }

    resultsText->setText(result);
}

void MainWindow::showTotalVolume()
{
    workoutsList->clear();
    auto volumes = diary.calculateTotalVolume();

    if(volumes.empty()) {
        workoutsList->addItem("Нет данных для расчета");
        return;
    }

    for(const auto& volume : volumes) {
        workoutsList->addItem(QString::fromStdString(volume));
    }
}

void MainWindow::findWorkoutsByType()
{
    QString type = searchTypeEdit->text();
    if(type.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите тип тренировки!");
        return;
    }

    auto workouts = diary.getWorkoutsByType(type.toStdString());
    resultsText->clear();

    if(workouts.empty()) {
        resultsText->setText("Тренировки не найдены!");
        return;
    }

    QString result = "Найдены тренировки типа: " + type + "\n\n";
    for(const auto& workout : workouts) {
        result += QString::fromStdString(workout.toString()) + "\n";
    }

    resultsText->setText(result);
}

void MainWindow::showLastWorkout()
{
    workoutsList->clear();
    Workout lastWorkout = diary.getLastWorkout();

    if(diary.getWorkoutCount() == 0) {
        workoutsList->addItem("Нет записей о тренировках");
        return;
    }

    workoutsList->addItem("Последняя тренировка:");
    workoutsList->addItem(QString::fromStdString(lastWorkout.toString()));
}

void MainWindow::findWorkoutsByDate()
{
    QString date = searchDateEdit->date().toString("dd.MM.yyyy");
    auto workouts = diary.getWorkoutsByDate(date.toStdString());
    resultsText->clear();

    if(workouts.empty()) {
        resultsText->setText("Тренировки за указанную дату не найдены!");
        return;
    }

    QString result = "Тренировки за " + date + ":\n\n";
    for(const auto& workout : workouts) {
        result += QString::fromStdString(workout.toString()) + "\n";
    }

    resultsText->setText(result);
}

void MainWindow::findWorkoutsByPeriod()
{
    QString startDate = searchStartDateEdit->date().toString("dd.MM.yyyy");
    QString endDate = searchEndDateEdit->date().toString("dd.MM.yyyy");

    auto workouts = diary.getWorkoutsByPeriod(startDate.toStdString(), endDate.toStdString());
    resultsText->clear();

    if(workouts.empty()) {
        resultsText->setText("Тренировки за указанный период не найдены!");
        return;
    }

    QString result = QString("Тренировки с %1 по %2:\n\n").arg(startDate).arg(endDate);
    for(const auto& workout : workouts) {
        result += QString::fromStdString(workout.toString()) + "\n";
    }

    resultsText->setText(result);
}

void MainWindow::loadData()
{
    diary.loadFromFile();
}