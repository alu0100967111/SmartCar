#include <QApplication>
#include <QObject>
#include <QDebug>
#include <QLabel>

#include "SmartCarBoard/smartcarboard.h"
#include "MainWindow/mainwindow.h"
#include "Common/error.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
