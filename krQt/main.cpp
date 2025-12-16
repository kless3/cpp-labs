#include "application/Application.h"

int main(int argc, char* argv[]) {
    Application app(argc, argv);
    
    if (!app.initialize()) {
        return -1;
    }

    return app.exec();
}
