// CalendarWidget.cpp
#include "CalendarWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPainter>
#include <QApplication>
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QLinearGradient>

DayWidget::DayWidget(QWidget* parent)
        : QWidget(parent), backgroundColor(QColor(255, 255, 255))
{
    // Еще больше увеличиваем размер карточки для лучшего отображения упражнений
    setFixedSize(180, 240); // Было 160, 200 - увеличили еще больше

    // Тень для красивого эффекта
    shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20);
    shadowEffect->setColor(QColor(0, 0, 0, 60));
    shadowEffect->setOffset(0, 4);
    setGraphicsEffect(shadowEffect);

    // Анимация цвета
    colorAnimation = new QPropertyAnimation(this, "backgroundColor");
    colorAnimation->setDuration(300);
    colorAnimation->setEasingCurve(QEasingCurve::OutCubic);

    layout = new QVBoxLayout(this);
    layout->setContentsMargins(15, 15, 15, 15); // Увеличили отступы еще больше
    layout->setSpacing(10); // Увеличили расстояние между элементами

    dateLabel = new QLabel("");
    dateLabel->setAlignment(Qt::AlignCenter);
    dateLabel->setStyleSheet("QLabel {"
                             "font-weight: bold;"
                             "font-size: 18px;" // Увеличили шрифт еще больше
                             "color: #2c3e50;"
                             "background-color: transparent;"
                             "padding: 8px;" // Увеличили padding
                             "border-radius: 12px;"
                             "}");

    workoutLabel = new QLabel("");
    workoutLabel->setAlignment(Qt::AlignCenter);
    workoutLabel->setStyleSheet("QLabel {"
                                "font-weight: bold;"
                                "font-size: 14px;" // Увеличили шрифт еще больше
                                "color: #ffffff;"
                                "background-color: #27ae60;"
                                "padding: 8px 12px;" // Увеличили padding
                                "border-radius: 12px;"
                                "margin: 4px;" // Увеличили margin
                                "}");

    exercisesLabel = new QLabel("");
    exercisesLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    exercisesLabel->setWordWrap(true);
    exercisesLabel->setStyleSheet("QLabel {"
                                  "font-size: 12px;" // Увеличили шрифт еще больше
                                  "color: #7f8c8d;"
                                  "background-color: transparent;"
                                  "padding: 6px;" // Увеличили padding
                                  "line-height: 1.4;" // Улучшили межстрочный интервал
                                  "}");
    exercisesLabel->setMaximumHeight(90); // Увеличили максимальную высоту для упражнений еще больше

    layout->addWidget(dateLabel);
    layout->addWidget(workoutLabel);
    layout->addWidget(exercisesLabel);
    layout->addStretch();

    contextMenu = new QMenu(this);
    contextMenu->setStyleSheet(
            "QMenu {"
            "background-color: white;"
            "border: 2px solid #bdc3c7;"
            "border-radius: 8px;"
            "padding: 12px;" // Увеличили padding
            "font-size: 14px;" // Увеличили шрифт
            "}"
            "QMenu::item {"
            "padding: 14px 35px;" // Увеличили padding
            "border-radius: 6px;" // Увеличили радиус
            "margin: 4px;" // Увеличили margin
            "}"
            "QMenu::item:selected {"
            "background-color: #3498db;"
            "color: white;"
            "}"
    );

    QAction* addAction = contextMenu->addAction("➕ Добавить тренировку");
    QAction* editAction = contextMenu->addAction("✏️ Редактировать");
    QAction* removeAction = contextMenu->addAction("🗑️ Удалить");

    connect(addAction, &QAction::triggered, this, &DayWidget::onAddWorkout);
    connect(editAction, &QAction::triggered, this, &DayWidget::onEditWorkout);
    connect(removeAction, &QAction::triggered, this, &DayWidget::onRemoveWorkout);

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &DayWidget::customContextMenuRequested, this, &DayWidget::showContextMenu);

    updateAppearance();
}

void DayWidget::setBackgroundColor(const QColor& color) {
    backgroundColor = color;
    update();
}

void DayWidget::setDate(const QString& newDate) {
    date = newDate;

    // Красивое форматирование даты
    QString day = newDate.left(2);
    QString month = newDate.mid(3, 2);

    QStringList monthNames = {"Янв", "Фев", "Мар", "Апр", "Май", "Июн",
                              "Июл", "Авг", "Сен", "Окт", "Ноя", "Дек"};
    int monthIndex = month.toInt() - 1;
    if (monthIndex >= 0 && monthIndex < monthNames.size()) {
        dateLabel->setText(QString("<div style='font-size: 20px; color: #2c3e50;'>%1</div>"
                                   "<div style='font-size: 12px; color: #7f8c8d;'>%2</div>")
                                   .arg(day)
                                   .arg(monthNames[monthIndex]));
    } else {
        dateLabel->setText(day);
    }
}

void DayWidget::setWorkout(const Workout& workout) {
    hasWorkout_ = true;
    workoutType = QString::fromStdString(workout.getType());

    exercises.clear();
    for (int i = 0; i < workout.getExerciseCount(); i++) {
        Exercise ex = workout.getExercise(i);
        QString exerciseStr = QString("• %1: %2×%3")
                .arg(QString::fromStdString(ex.name))
                .arg(ex.sets)
                .arg(ex.reps);
        if (ex.weight > 0) {
            exerciseStr += QString(" (%4кг)").arg(ex.weight);
        }
        exercises.append(exerciseStr);
    }

    // Стилизация типа тренировки в зависимости от содержания
    QString workoutStyle;
    if (workoutType.contains("силов", Qt::CaseInsensitive) || workoutType.contains("power", Qt::CaseInsensitive)) {
        workoutStyle = "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #e74c3c, stop:1 #c0392b);";
    } else if (workoutType.contains("кардио", Qt::CaseInsensitive) || workoutType.contains("cardio", Qt::CaseInsensitive)) {
        workoutStyle = "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #3498db, stop:1 #2980b9);";
    } else if (workoutType.contains("отдых", Qt::CaseInsensitive) || workoutType.contains("rest", Qt::CaseInsensitive)) {
        workoutStyle = "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #95a5a6, stop:1 #7f8c8d);";
    } else {
        workoutStyle = "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #27ae60, stop:1 #229954);";
    }

    workoutLabel->setStyleSheet("QLabel {"
                                "font-weight: bold;"
                                "font-size: 13px;" // Увеличили шрифт еще больше
                                "color: white;"
                                "padding: 8px 12px;" // Увеличили padding
                                "border-radius: 12px;"
                                "margin: 4px;" // Увеличили margin
                                + workoutStyle +
                                "}");
    workoutLabel->setText(workoutType);

    // Форматирование упражнений - показываем больше упражнений
    QString exercisesText;
    int maxExercises = 5; // Увеличили количество отображаемых упражнений с 4 до 5
    for (int i = 0; i < qMin(maxExercises, exercises.size()); i++) {
        exercisesText += exercises[i] + "\n";
    }
    if (exercises.size() > maxExercises) {
        exercisesText += QString("... +%1 еще").arg(exercises.size() - maxExercises);
    }
    exercisesLabel->setText(exercisesText);

    updateAppearance();
}

void DayWidget::clearWorkout() {
    hasWorkout_ = false;
    workoutType.clear();
    exercises.clear();
    workoutLabel->clear();
    exercisesLabel->clear();
    updateAppearance();
}

void DayWidget::updateAppearance() {
    // Стиль будет применяться в paintEvent
    update();
}

void DayWidget::animateHover(bool enter) {
    colorAnimation->stop();

    QColor startColor = backgroundColor;
    QColor endColor;

    if (enter) {
        if (hasWorkout_) {
            endColor = QColor(245, 255, 250); // Светло-зеленый при наведении
        } else {
            endColor = QColor(250, 250, 255); // Светло-голубой при наведении
        }
        shadowEffect->setBlurRadius(25);
        shadowEffect->setOffset(0, 6);
    } else {
        if (hasWorkout_) {
            endColor = QColor(255, 255, 255); // Белый фон
        } else {
            endColor = QColor(255, 255, 255); // Белый фон
        }
        shadowEffect->setBlurRadius(20);
        shadowEffect->setOffset(0, 4);
    }

    colorAnimation->setStartValue(startColor);
    colorAnimation->setEndValue(endColor);
    colorAnimation->start();
}

void DayWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        // Анимация нажатия
        QPropertyAnimation* pressAnimation = new QPropertyAnimation(this, "geometry");
        pressAnimation->setDuration(100);
        pressAnimation->setStartValue(geometry());
        pressAnimation->setEndValue(geometry().adjusted(1, 1, -1, -1));
        pressAnimation->start(QPropertyAnimation::DeleteWhenStopped);

        emit workoutClicked(date);
    }
    QWidget::mousePressEvent(event);
}

void DayWidget::enterEvent(QEvent* event) {
    animateHover(true);
    QWidget::enterEvent(event);
}

void DayWidget::leaveEvent(QEvent* event) {
    animateHover(false);
    QWidget::leaveEvent(event);
}

void DayWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    QRect rect = this->rect().adjusted(2, 2, -2, -2);

    // Градиентный фон
    QLinearGradient gradient(rect.topLeft(), rect.bottomRight());

    if (hasWorkout_) {
        // Красивый градиент для дней с тренировками
        gradient.setColorAt(0, QColor(255, 255, 255));
        gradient.setColorAt(0.3, backgroundColor);
        gradient.setColorAt(1, QColor(245, 255, 250));

        // Рамка с градиентом
        QLinearGradient borderGradient(rect.topLeft(), rect.bottomRight());
        borderGradient.setColorAt(0, QColor(46, 204, 113));
        borderGradient.setColorAt(1, QColor(39, 174, 96));

        painter.setPen(QPen(borderGradient, 3));
    } else {
        // Градиент для пустых дней
        gradient.setColorAt(0, QColor(255, 255, 255));
        gradient.setColorAt(0.5, backgroundColor);
        gradient.setColorAt(1, QColor(248, 249, 250));

        // Серая рамка для пустых дней
        painter.setPen(QPen(QColor(189, 195, 199), 2));
    }

    painter.setBrush(gradient);

    // Рисуем основной прямоугольник с закругленными углами
    painter.drawRoundedRect(rect, 12, 12);

    // Дополнительные декоративные элементы
    if (hasWorkout_) {
        // Тонкая внутренняя тень
        painter.setPen(QPen(QColor(39, 174, 96, 30), 1));
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect.adjusted(1, 1, -1, -1), 11, 11);
    }

    // Индикатор текущего дня
    QDate currentDate = QDate::currentDate();
    QString currentDateStr = currentDate.toString("dd.MM.yyyy");
    if (date == currentDateStr) {
        painter.setPen(QPen(QColor(241, 196, 15), 3));
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect.adjusted(3, 3, -3, -3), 10, 10);

        // Желтый акцентный уголок
        QPolygon triangle;
        triangle << QPoint(rect.right() - 15, rect.top() + 2)
                 << QPoint(rect.right() - 2, rect.top() + 2)
                 << QPoint(rect.right() - 2, rect.top() + 15);
        painter.setBrush(QColor(241, 196, 15));
        painter.setPen(Qt::NoPen);
        painter.drawPolygon(triangle);
    }

    QWidget::paintEvent(event);
}

void DayWidget::showContextMenu(const QPoint& pos) {
    QAction* editAction = contextMenu->actions().at(1);
    QAction* removeAction = contextMenu->actions().at(2);

    editAction->setEnabled(hasWorkout_);
    removeAction->setEnabled(hasWorkout_);

    contextMenu->exec(mapToGlobal(pos));
}

void DayWidget::onAddWorkout() {
    emit addWorkoutRequested(date);
}

void DayWidget::onEditWorkout() {
    if (hasWorkout_) {
        emit editWorkoutRequested(date);
    }
}

void DayWidget::onRemoveWorkout() {
    if (hasWorkout_) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("🗑️ Удаление тренировки");
        msgBox.setText(QString("Удалить тренировку <b>\"%1\"</b> на <b>%2</b>?").arg(workoutType).arg(date));
        msgBox.setInformativeText("Это действие нельзя отменить.");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setStyleSheet(
                "QMessageBox {"
                "background-color: white;"
                "border: 2px solid #bdc3c7;"
                "border-radius: 10px;"
                "}"
                "QMessageBox QPushButton {"
                "padding: 12px 24px;" // Увеличили padding кнопок еще больше
                "border-radius: 6px;"
                "font-weight: bold;"
                "min-width: 100px;" // Увеличили минимальную ширину
                "font-size: 14px;" // Увеличили шрифт
                "}"
        );

        if (msgBox.exec() == QMessageBox::Yes) {
            emit removeWorkoutRequested(date);
        }
    }
}

CalendarWidget::CalendarWidget(TrainingDiary* diary, QWidget* parent)
        : QWidget(parent), trainingDiary(diary)
{
    setupUI();
    goToCurrentWeek();
}

CalendarWidget::~CalendarWidget() {
    qDeleteAll(dayWidgets);
}

void CalendarWidget::setupUI() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(25); // Увеличили расстояние между элементами еще больше
    mainLayout->setContentsMargins(25, 25, 25, 25); // Увеличили отступы еще больше

    // Week navigation with style
    QHBoxLayout* navLayout = new QHBoxLayout();

    prevWeekBtn = new QPushButton("◀ Предыдущая неделя");
    nextWeekBtn = new QPushButton("Следующая неделя ▶");
    currentWeekBtn = new QPushButton("📅 Текущая неделя");

    // Стилизация кнопок - увеличенные размеры еще больше
    QString buttonStyle =
            "QPushButton {"
            "background-color: #3498db;"
            "color: white;"
            "border: none;"
            "padding: 14px 24px;" // Увеличили padding еще больше
            "border-radius: 8px;" // Увеличили радиус
            "font-weight: bold;"
            "font-size: 15px;" // Увеличили шрифт еще больше
            "min-height: 25px;" // Добавили минимальную высоту
            "}"
            "QPushButton:hover {"
            "background-color: #2980b9;"
            "}"
            "QPushButton:pressed {"
            "background-color: #21618c;"
            "}";

    prevWeekBtn->setStyleSheet(buttonStyle);
    nextWeekBtn->setStyleSheet(buttonStyle);
    currentWeekBtn->setStyleSheet(buttonStyle);

    weekLabel = new QLabel();
    weekLabel->setAlignment(Qt::AlignCenter);
    weekLabel->setStyleSheet("QLabel {"
                             "font-size: 20px;" // Увеличили шрифт еще больше
                             "font-weight: bold;"
                             "color: #2c3e50;"
                             "padding: 15px;" // Увеличили padding
                             "background-color: #ecf0f1;"
                             "border-radius: 12px;" // Увеличили радиус
                             "}");

    navLayout->addWidget(prevWeekBtn);
    navLayout->addStretch();
    navLayout->addWidget(weekLabel);
    navLayout->addStretch();
    navLayout->addWidget(currentWeekBtn);
    navLayout->addWidget(nextWeekBtn);

    // Calendar grid
    QWidget* calendarContainer = new QWidget();
    calendarContainer->setStyleSheet("QWidget { background-color: #f8f9fa; border-radius: 15px; padding: 20px; }");
    QVBoxLayout* containerLayout = new QVBoxLayout(calendarContainer);

    gridLayout = new QGridLayout();
    gridLayout->setSpacing(15); // Увеличили расстояние между карточками еще больше
    gridLayout->setContentsMargins(20, 20, 20, 20); // Увеличили отступы еще больше

    // Day headers with style
    QStringList dayNames = {"ПОНЕДЕЛЬНИК", "ВТОРНИК", "СРЕДА", "ЧЕТВЕРГ", "ПЯТНИЦА", "СУББОТА", "ВОСКРЕСЕНЬЕ"};
    for (int i = 0; i < 7; i++) {
        QLabel* dayHeader = new QLabel(dayNames[i]);
        dayHeader->setAlignment(Qt::AlignCenter);
        dayHeader->setFixedHeight(45); // Увеличили высоту заголовков еще больше
        dayHeader->setStyleSheet("QLabel {"
                                 "font-weight: bold;"
                                 "font-size: 16px;" // Увеличили шрифт еще больше
                                 "background-color: #34495e;"
                                 "color: white;"
                                 "padding: 10px;" // Увеличили padding
                                 "border-radius: 10px;" // Увеличили радиус
                                 "}");
        gridLayout->addWidget(dayHeader, 0, i);
    }

    createDayWidgets();
    containerLayout->addLayout(gridLayout);

    mainLayout->addLayout(navLayout);
    mainLayout->addWidget(calendarContainer);

    connect(prevWeekBtn, &QPushButton::clicked, this, &CalendarWidget::previousWeek);
    connect(nextWeekBtn, &QPushButton::clicked, this, &CalendarWidget::nextWeek);
    connect(currentWeekBtn, &QPushButton::clicked, this, &CalendarWidget::goToCurrentWeek);
}

void CalendarWidget::createDayWidgets() {
    dayWidgets.clear();

    for (int i = 0; i < 7; i++) {
        DayWidget* dayWidget = new DayWidget();
        dayWidgets.append(dayWidget);
        gridLayout->addWidget(dayWidget, 1, i);

        connect(dayWidget, &DayWidget::workoutClicked, this, &CalendarWidget::onDayClicked);
        connect(dayWidget, &DayWidget::addWorkoutRequested, this, &CalendarWidget::onAddWorkoutRequested);
        connect(dayWidget, &DayWidget::editWorkoutRequested, this, &CalendarWidget::onEditWorkoutRequested);
        connect(dayWidget, &DayWidget::removeWorkoutRequested, this, &CalendarWidget::onRemoveWorkoutRequested);
    }
}

void CalendarWidget::updateCalendar() {
    auto weekDates = trainingDiary->getWeekDates(currentStartDate.toStdString());

    // weekDates[0] = понедельник, weekDates[1] = вторник, ..., weekDates[6] = воскресенье
    // Но dayWidgets[0] должен быть понедельником, dayWidgets[1] - вторником и т.д.
    for (int i = 0; i < 7; i++) {
        QString date = QString::fromStdString(weekDates[i]);
        dayWidgets[i]->setDate(date);

        Workout workout = trainingDiary->getWorkoutForDate(date.toStdString());
        if (trainingDiary->hasWorkoutForDate(date.toStdString())) {
            dayWidgets[i]->setWorkout(workout);
        } else {
            dayWidgets[i]->clearWorkout();
        }
    }

    updateWeekLabel();
}

void CalendarWidget::updateWeekLabel() {
    auto weekDates = trainingDiary->getWeekDates(currentStartDate.toStdString());
    QString startDate = QString::fromStdString(weekDates[0]);
    QString endDate = QString::fromStdString(weekDates[6]);

    weekLabel->setText(QString("📅 Неделя: %1 - %2   |   🏋️ Программа: %3")
                               .arg(startDate)
                               .arg(endDate)
                               .arg(QString::fromStdString(trainingDiary->getCurrentProgram().getName())));
}

void CalendarWidget::nextWeek() {
    currentStartDate = QString::fromStdString(trainingDiary->getNextWeek(currentStartDate.toStdString()));
    updateCalendar();
}

void CalendarWidget::previousWeek() {
    currentStartDate = QString::fromStdString(trainingDiary->getPreviousWeek(currentStartDate.toStdString()));
    updateCalendar();
}

void CalendarWidget::goToCurrentWeek() {
    QDate today = QDate::currentDate();
    // Находим понедельник текущей недели
    // QDate::dayOfWeek() возвращает 1-7 (1=Понедельник, 7=Воскресенье)
    int daysToMonday = (today.dayOfWeek() - 1); // 0 для понедельника, 1 для вторника и т.д.
    QDate startOfWeek = today.addDays(-daysToMonday);
    currentStartDate = startOfWeek.toString("dd.MM.yyyy");
    updateCalendar();
}

void CalendarWidget::onDayClicked(const QString& date) {
    Workout workout = trainingDiary->getWorkoutForDate(date.toStdString());
    emit workoutSelected(date, workout);
}

void CalendarWidget::onAddWorkoutRequested(const QString& date) {
    emit workoutSelected(date, Workout());
}

void CalendarWidget::onEditWorkoutRequested(const QString& date) {
    Workout workout = trainingDiary->getWorkoutForDate(date.toStdString());
    emit workoutSelected(date, workout);
}

void CalendarWidget::onRemoveWorkoutRequested(const QString& date) {
    trainingDiary->getCurrentProgram().removeWorkoutForDate(date.toStdString());
    trainingDiary->saveToFile();
    updateCalendar();

    // Показать уведомление
    QMessageBox::information(this, "✅ Успех", "Тренировка удалена!");
}