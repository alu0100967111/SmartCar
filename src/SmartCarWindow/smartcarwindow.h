#ifndef SMARTCARWINDOW_H
#define SMARTCARWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QApplication> // Para coger tamaño pantalla
#include <QDesktopWidget> // Para coger tamaño pantalla
#include <QShowEvent>

#include "SmartCarBoard/smartcarboard.h"

namespace Ui {
class SmartCarWindow;
}

// Clase de la Ventana de SmartCar
class SmartCarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SmartCarWindow(const struct params &config, const bool &auto_, QWidget *parent = 0);
    ~SmartCarWindow();

private:
    Ui::SmartCarWindow *ui;
    void InicializeWindow(const struct params &config, const struct size_struct &frame_size);
    void InicializeLayout(const int row, const int column);
    struct size_struct GetFrameSize(const struct params &config);

protected:
    QGridLayout* smart_car_layout;
    SmartCarBoard* smart_car_board;
    bool auto_;

public slots:
    int ok_clicked();
    int start_clicked();

};

#endif // SMARTCARWINDOW_H
