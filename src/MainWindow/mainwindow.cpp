#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    auto_(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->showMaximized();
    //ui->p_label->setVisible(false);// Set the status of the opposite
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_auto_checkbox_clicked()
{
    if(auto_ == false){
        ui->inputobs->setPlaceholderText("Introduce % de obstáculos");
        auto_ = true;
    }else{
        ui->inputobs->setPlaceholderText("");
        auto_ = false;
    }

}

bool MainWindow::on_simular_clicked()
{
    if (ui->inputfilas->text() == "") {
      criticalerror("Error en filas", "Introduce un número de filas > 1 ");
    }
    else if(ui->inputfilas->text().count(QRegExp("[a-z]")) || ui->inputfilas->text().count(QRegExp("[A-Z]"))
             || (ui->inputfilas->text().toInt() == 1 && ui->inputfilas->text().toInt() == 0)) {
      criticalerror("Error en filas", "Introduce un número válido de filas");
    }
    else if(ui->inputcol->text() == "") {
       criticalerror("Error en columnas", "Introduce un número válido de columnas");
    }
    else if(ui->inputcol->text().count(QRegExp("[a-z]")) || ui->inputcol->text().count(QRegExp("[A-Z]"))
            || (ui->inputfilas->text().toInt() == 0 && ui->inputfilas->text().toInt() == 1)) {
       criticalerror("Error en columnas", "Introduce un número válido de columnas");
    }
    else {
       config.row_number = ui->inputfilas->text().toInt();
       config.col_number = ui->inputcol->text().toInt();
       config.block_number = ui->inputobs->text().toInt();
       config.distance_algorithm = 1; //TEMP

       qDebug() << ui->inputobs->text().remove(QChar('%'), Qt::CaseInsensitive);

       if (auto_) {
          config.block_number = (ui->inputfilas->text().toInt()+ui->inputcol->text().toInt()) /
                  ui->inputobs->text().remove(QChar('%'), Qt::CaseInsensitive).toInt();
          qDebug() << config.block_number;
       } else {
          config.block_number = ui->inputobs->text().toInt();
       }

       SmartCarWindow* smart_car_window = new SmartCarWindow(config);
       smart_car_window->show();

       this->close();
       return true;
    }
    return false;
}

struct params MainWindow::get_params(){
    return config;
}
