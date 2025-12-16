#include "ui/NavigationHeader.h"
#include "service/DateService.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

NavigationHeader::NavigationHeader(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void NavigationHeader::setDate(const QDate& date) {
    QString dateStr = DateService::formatDate(date);
    QString dayOfWeek = DateService::getDayOfWeek(date);
    dateLabel->setText(dateStr + " (" + dayOfWeek + ")");
}

void NavigationHeader::setupUI() {
    auto* layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(15);

    prevButton = new QPushButton("◀");
    prevButton->setFixedSize(50, 50);
    prevButton->setToolTip("Предыдущий день");

    dateLabel = new QLabel();
    dateLabel->setAlignment(Qt::AlignCenter);
    dateLabel->setStyleSheet(
        "font-size: 20px; font-weight: bold; background: white; padding: 12px; border-radius: 5px;"
    );

    nextButton = new QPushButton("▶");
    nextButton->setFixedSize(50, 50);
    nextButton->setToolTip("Следующий день");

    layout->addWidget(prevButton);
    layout->addWidget(dateLabel, 1);
    layout->addWidget(nextButton);

    connect(prevButton, &QPushButton::clicked, this, &NavigationHeader::previousDay);
    connect(nextButton, &QPushButton::clicked, this, &NavigationHeader::nextDay);
}
