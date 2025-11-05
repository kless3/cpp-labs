// main.cpp
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Set application style
    app.setStyleSheet(
            "QMainWindow { background-color: #f5f5f5; }"
            "QPushButton {"
            "background-color: #007bff;"
            "color: white;"
            "border: none;"
            "padding: 8px 16px;"
            "border-radius: 4px;"
            "font-weight: bold;"
            "}"
            "QPushButton:hover { background-color: #0056b3; }"
            "QPushButton:pressed { background-color: #004085; }"
            "QComboBox {"
            "padding: 6px;"
            "border: 1px solid #ced4da;"
            "border-radius: 4px;"
            "background-color: white;"
            "}"
            "QLineEdit {"
            "padding: 6px;"
            "border: 1px solid #ced4da;"
            "border-radius: 4px;"
            "}"
            "QListWidget {"
            "border: 1px solid #ced4da;"
            "border-radius: 4px;"
            "background-color: white;"
            "}"
    );

    MainWindow window;
    window.show();

    return app.exec();
}