#ifndef SMARTCARWINDOW_H
#define SMARTCARWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

#include "smartcarboard.h"

namespace Ui {
class SmartCarWindow;
}

// Clase de la Ventana de SmartCar
class SmartCarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SmartCarWindow(const struct params &config, QWidget *parent = 0);
    ~SmartCarWindow();

private:
    Ui::SmartCarWindow *ui;
    void InicializeLayout(const int row, const int column);

    QGridLayout *smart_car_layout;
    SmartCarBoard smart_car_board;
};

#endif // SMARTCARWINDOW_H
