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
    void setupUI() const;

    QLineEdit* descriptionEdit{nullptr};
    QDateEdit* dateEdit{nullptr};
    QTimeEdit* timeEdit{nullptr};
    QComboBox* priorityCombo{nullptr};
};
