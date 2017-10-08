#include "mainwindow.h"
#include "smartcarwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SmartCarWindow smart_car_window(5,5);
    smart_car_window.show();

    return a.exec();
}
