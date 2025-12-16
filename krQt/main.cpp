#include "application/Application.h"

int main(int argc, char* argv[]) {
    if (Application app(argc, argv); !app.initialize()) {
        return -1;
    } else {
        return Application::exec();
    }
}
