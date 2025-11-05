#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDate>
#include <QMenu>
#include <QAction>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include "TrainingDiary.h"

class DayWidget : public QWidget
{
Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor)

public:
    DayWidget(QWidget* parent = nullptr);
    void setDate(const QString& date);
    void setWorkout(const Workout& workout);
    void clearWorkout();
    bool hasWorkout() const { return hasWorkout_; }
    QString getDate() const { return date; }

    QColor getBackgroundColor() const { return backgroundColor; }
    void setBackgroundColor(const QColor& color);

signals:
    void addWorkoutRequested(const QString& date);
    void editWorkoutRequested(const QString& date);
    void removeWorkoutRequested(const QString& date);
    void workoutClicked(const QString& date);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private slots:
    void showContextMenu(const QPoint& pos);
    void onAddWorkout();
    void onEditWorkout();
    void onRemoveWorkout();

private:
    void updateAppearance();
    void animateHover(bool enter);

    QString date;
    bool hasWorkout_ = false;
    QString workoutType;
    QStringList exercises;
    QColor backgroundColor;
    QLabel* dateLabel;
    QLabel* workoutLabel;
    QLabel* exercisesLabel;
    QVBoxLayout* layout;
    QMenu* contextMenu;
    QPropertyAnimation* colorAnimation;
    QGraphicsDropShadowEffect* shadowEffect;
};

class CalendarWidget : public QWidget
{
Q_OBJECT

public:
    CalendarWidget(TrainingDiary* diary, QWidget* parent = nullptr);
    ~CalendarWidget();
    void updateCalendar();

public slots:
    void nextWeek();
    void previousWeek();
    void goToCurrentWeek();
    void onDayClicked(const QString& date);
    void onAddWorkoutRequested(const QString& date);
    void onEditWorkoutRequested(const QString& date);
    void onRemoveWorkoutRequested(const QString& date);

signals:
    void workoutSelected(const QString& date, const Workout& workout);

private:
    void setupUI();
    void updateWeekLabel();
    void createDayWidgets();

    TrainingDiary* trainingDiary;
    QGridLayout* gridLayout;
    QLabel* weekLabel;
    QPushButton* prevWeekBtn;
    QPushButton* nextWeekBtn;
    QPushButton* currentWeekBtn;

    QVector<DayWidget*> dayWidgets;
    QString currentStartDate;
};

#endif