#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Basic Studio");
    w.setStyleSheet("QLabel {color: white}");
    w.show();
    
    return a.exec();
}
