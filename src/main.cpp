#include <QApplication>
#include <QObject>
#include <QDebug>
#include <QLabel>

#include "smartcarboard.h"
#include "mainwindow.h"
#include "error.h"

int QGridLayout::heightForWidth(int w) const {
    return w;
}

bool QGridLayout::hasHeightForWidth() const{
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
