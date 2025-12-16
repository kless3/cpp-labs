#include "application/Application.h"
#include "application/DailyPlannerApp.h"
#include "exceptions/AppException.h"

Application::Application(int& argc, char** argv)
    : QApplication(argc, argv)
{
}

Application::~Application() = default;

bool Application::initialize() {
    try {
        mainWindow = std::make_unique<DailyPlannerApp>();
        mainWindow->show();
        return true;
    } catch (const AppException& e) {
        qCritical("Failed to initialize application: %s", e.what());
        return false;
    }
}
