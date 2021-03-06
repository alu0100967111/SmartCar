#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSize>
#include <QDesktopWidget>
#include <QDebug>


#include "Common/error.h"
#include "SmartCarWindow/smartcarwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void centerAndResize();
    bool get_block_conf();
    struct params get_params();
    ~MainWindow();

public slots:
    bool on_simular_clicked();
    void on_auto_checkbox_clicked();
    //void on_inputcol_returnPressed();

private:
    Ui::MainWindow *ui;
    bool auto_;
    struct params config;
};

#endif // MAINWINDOW_H
