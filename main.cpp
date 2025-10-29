#include <QApplication>
#include <QLabel>
#include <QWidget>
#include "MainWindow.h"

int main(int argc, char *argv[]) 
{
    // app object
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}