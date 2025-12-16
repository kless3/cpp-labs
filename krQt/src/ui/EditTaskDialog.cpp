#include "ui/EditTaskDialog.h"
#include "utils/StyleLoader.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QGroupBox>

EditTaskDialog::EditTaskDialog(const Task& task, QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Редактировать задачу");
    setFixedSize(500, 250);

    QString styleSheet = StyleLoader::loadStyleSheet("resources/styles/edit_task_dialog.qss");
    setStyleSheet(styleSheet);

    auto* mainLayout = new QVBoxLayout(this);

    auto* headerLabel = new QLabel("Редактировать задачу");
    headerLabel->setStyleSheet("font-size: 18px; font-weight: bold; margin: 10px;");

    auto* contentGroup = new QGroupBox();
    auto* formLayout = new QFormLayout(contentGroup);

    descriptionEdit = new QLineEdit(QString::fromStdString(task.getDescription()));
    descriptionEdit->setPlaceholderText("Введите описание задачи");

    priorityCombo = new QComboBox();
    priorityCombo->addItem("⭐ Низкий", 1);
    priorityCombo->addItem("⭐⭐ Средний", 2);
    priorityCombo->addItem("⭐⭐⭐ Высокий", 3);
    priorityCombo->addItem("⭐⭐⭐⭐ Важный", 4);
    priorityCombo->addItem("⭐⭐⭐⭐⭐ Критический", 5);
    priorityCombo->setCurrentIndex(task.getPriority() - 1);

    formLayout->addRow("Описание:", descriptionEdit);
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

QString EditTaskDialog::getDescription() const {
    return descriptionEdit->text();
}

int EditTaskDialog::getPriority() const {
    return priorityCombo->currentData().toInt();
}

void EditTaskDialog::setupUI() {
}
