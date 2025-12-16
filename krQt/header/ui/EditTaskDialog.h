#pragma once

#include "core/Task.h"

#include <QDialog>

class QLineEdit;
class QComboBox;

class EditTaskDialog : public QDialog {
    Q_OBJECT

public:
    explicit EditTaskDialog(const Task& task, QWidget* parent = nullptr);

    QString getDescription() const;
    int getPriority() const;

private:
    void setupUI() const;

    QLineEdit* descriptionEdit{nullptr};
    QComboBox* priorityCombo{nullptr};
};
