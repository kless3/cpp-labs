#pragma once

#include <QApplication>

class DailyPlannerApp;

class Application : public QApplication {
    Q_OBJECT

public:
    Application(int& argc, char** argv);
    ~Application() override;

    bool initialize();

private:
    DailyPlannerApp* mainWindow;
};
