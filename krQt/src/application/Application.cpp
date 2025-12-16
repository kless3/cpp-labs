#include "application/Application.h"
#include "application/DailyPlannerApp.h"
#include "exceptions/AppException.h"

Application::Application(int& argc, char** argv)
    : QApplication(argc, argv)
    , mainWindow(nullptr)
{
}

Application::~Application() {
    delete mainWindow;
}

bool Application::initialize() {
    try {
        mainWindow = new DailyPlannerApp();
        mainWindow->show();
        return true;
    } catch (const AppException& e) {
        qCritical("Failed to initialize application: %s", e.what());
        return false;
    }
}
