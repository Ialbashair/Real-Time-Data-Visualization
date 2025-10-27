#include <QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[]) 
{
    // app object
    QApplication app(argc, argv)    ;

    // main window/widget
    QWidget window;
    window.setWindowTitle("Real-Time Visualizer Prototype");

    // add lable
    QLabel label("Qt is running!", &window);
    label.setGeometry(50, 50, 200, 30);

    // show window and start Qt loop
    window.show();
    return app.exec();
}