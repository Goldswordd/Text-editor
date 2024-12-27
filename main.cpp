#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Text Editor");
    mainWindow.resize(960, 1080);
    mainWindow.show();

    return app.exec();
}
