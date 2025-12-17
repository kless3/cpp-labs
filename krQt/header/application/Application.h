#pragma once

#include <QApplication>
#include <memory>

class DailyPlannerApp;

class Application : public QApplication {
    Q_OBJECT

public:
    Application(int& argc, char** argv);
    ~Application() override;

    bool initialize();
    static int exec();

private:
    std::unique_ptr<DailyPlannerApp> mainWindow{nullptr};
};
