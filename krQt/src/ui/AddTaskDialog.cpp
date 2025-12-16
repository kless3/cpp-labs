#include "ui/AddTaskDialog.h"
#include "utils/StyleLoader.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QDate>
#include <QTime>

AddTaskDialog::AddTaskDialog(QWidget* parent)
    : QDialog(parent)
    , descriptionEdit(new QLineEdit())
    , dateEdit(new QDateEdit(QDate::currentDate()))
    , timeEdit(new QTimeEdit(QTime::currentTime()))
    , priorityCombo(new QComboBox())
{
    setWindowTitle("Добавить задачу");
    setFixedSize(500, 350);

    QString styleSheet = StyleLoader::loadStyleSheet("resources/styles/add_task_dialog.qss");
    setStyleSheet(styleSheet);

    auto* mainLayout = new QVBoxLayout(this);

    auto* headerLabel = new QLabel("Новая задача");
    headerLabel->setStyleSheet("font-size: 18px; font-weight: bold; margin: 10px;");

    auto* contentGroup = new QGroupBox();
    auto* formLayout = new QFormLayout(contentGroup);

    descriptionEdit->setPlaceholderText("Введите описание задачи");

    dateEdit->setCalendarPopup(true);
    dateEdit->setDisplayFormat("dd.MM.yyyy");

    timeEdit->setDisplayFormat("HH:mm");
    priorityCombo->addItem("⭐ Низкий", 1);
    priorityCombo->addItem("⭐⭐ Средний", 2);
    priorityCombo->addItem("⭐⭐⭐ Высокий", 3);
    priorityCombo->addItem("⭐⭐⭐⭐ Важный", 4);
    priorityCombo->addItem("⭐⭐⭐⭐⭐ Критический", 5);
    priorityCombo->setCurrentIndex(1);

    formLayout->addRow("Описание:", descriptionEdit);
    formLayout->addRow("Дата:", dateEdit);
    formLayout->addRow("Время:", timeEdit);
    formLayout->addRow("Приоритет:", priorityCombo);

    auto* buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel
    );

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    mainLayout->addWidget(headerLabel);
    mainLayout->addWidget(contentGroup);
    mainLayout->addWidget(buttonBox);
}

QString AddTaskDialog::getDescription() const {
    return descriptionEdit->text();
}

QString AddTaskDialog::getDate() const {
    return dateEdit->date().toString("yyyy-MM-dd");
}

QString AddTaskDialog::getTime() const {
    return timeEdit->time().toString("HH:mm");
}

int AddTaskDialog::getPriority() const {
    return priorityCombo->currentData().toInt();
}

void AddTaskDialog::setupUI() const {
    // UI setup is done directly in the constructor
    // This method is kept for potential future use or interface compatibility
}
