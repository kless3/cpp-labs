#pragma once

#include <QDialog>

class QLineEdit;
class QDateEdit;
class QTimeEdit;
class QComboBox;

class AddTaskDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddTaskDialog(QWidget* parent = nullptr);

    QString getDescription() const;
    QString getDate() const;
    QString getTime() const;
    int getPriority() const;

private:
    void setupUI();

    QLineEdit* descriptionEdit;
    QDateEdit* dateEdit;
    QTimeEdit* timeEdit;
    QComboBox* priorityCombo;
};
