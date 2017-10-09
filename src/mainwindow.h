#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSize>
#include <QDesktopWidget>
#include <QDebug>

#include "error.h"
#include "smartcarwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void centerAndResize();
    struct params get_params();
    ~MainWindow();

public slots:
    bool on_simular_clicked();

    //void on_inputcol_returnPressed();

private:
    Ui::MainWindow *ui;
    struct params config;
};

#endif // MAINWINDOW_H
