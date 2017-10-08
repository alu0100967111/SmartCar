#include <QApplication>
#include <QObject>
#include <QDebug>
#include <QLabel>

#include "smartcarboard.h"
#include "mainwindow.h"
#include "error.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
