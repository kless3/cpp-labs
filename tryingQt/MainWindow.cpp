// MainWindow.cpp
#include "MainWindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent)
{
    trainingDiary = new TrainingDiary();
    setupUI();
    setupMenu();

    setWindowTitle("Дневник тренировок");
    setMinimumSize(1000, 700);
}

void MainWindow::setupUI() {
    QWidget* centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    // Program selection
    QHBoxLayout* programLayout = new QHBoxLayout();

    programLayout->addWidget(new QLabel("Программа:"));

    programComboBox = new QComboBox();
    updateProgramComboBox();
    programLayout->addWidget(programComboBox);

    QPushButton* manageProgramsBtn = new QPushButton("Управление программами");
    programLayout->addWidget(manageProgramsBtn);

    programLayout->addStretch();

    mainLayout->addLayout(programLayout);

    // Calendar
    calendarWidget = new CalendarWidget(trainingDiary);
    mainLayout->addWidget(calendarWidget);

    connect(manageProgramsBtn, &QPushButton::clicked, this, &MainWindow::managePrograms);
    connect(programComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onProgramChanged);
    connect(calendarWidget, &CalendarWidget::workoutSelected, this, &MainWindow::showWorkoutDialog);
}

void MainWindow::setupMenu() {
    QMenu* fileMenu = menuBar()->addMenu("Файл");

    QAction* exitAction = fileMenu->addAction("Выход");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    QMenu* trainingMenu = menuBar()->addMenu("Тренировки");

    QAction* manageProgramsAction = trainingMenu->addAction("Управление программами");
    connect(manageProgramsAction, &QAction::triggered, this, &MainWindow::managePrograms);
}

void MainWindow::showWorkoutDialog(const QString& date, const Workout& workout) {
    WorkoutDialog dialog(date, workout, this);
    if (dialog.exec() == QDialog::Accepted) {
        Workout newWorkout = dialog.getWorkout();
        trainingDiary->setWorkoutForDate(date.toStdString(), newWorkout);
        calendarWidget->updateCalendar();

        statusBar()->showMessage("Тренировка сохранена: " + date, 3000);
    }
}
void MainWindow::managePrograms() {
    ProgramDialog dialog(trainingDiary, this);
    if (dialog.exec() == QDialog::Accepted) {
        updateProgramComboBox();
        calendarWidget->updateCalendar();
    }
}

void MainWindow::updateProgramComboBox() {
    programComboBox->clear();
    for (const auto& program : trainingDiary->getAllPrograms()) {
        programComboBox->addItem(QString::fromStdString(program.getName()));
    }
    programComboBox->setCurrentIndex(trainingDiary->getCurrentProgramIndex());
}

void MainWindow::onProgramChanged(int index) {
    if (index >= 0 && index < trainingDiary->getProgramCount()) {
        trainingDiary->setCurrentProgram(index);
        calendarWidget->updateCalendar();
    }
}