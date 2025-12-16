#pragma once

#include <QWidget>
#include <QDate>

class QLabel;
class QPushButton;

class NavigationHeader : public QWidget {
    Q_OBJECT

public:
    explicit NavigationHeader(QWidget* parent = nullptr);

    void setDate(const QDate& date);

signals:
    void previousDay();
    void nextDay();

private:
    void setupUI();

    QLabel* dateLabel;
    QPushButton* prevButton;
    QPushButton* nextButton;
};
