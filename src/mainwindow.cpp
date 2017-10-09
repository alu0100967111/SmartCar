#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
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

/*
void MainWindow::on_boton_clicked()
{
    //ui->p_label->setVisible(!ui->p_label->isVisible());// Set the status of the opposite

    //ui->p_label->setText(ui->lineEdit->text());
    //ui->p_label->adjustSize();

    if(ui->inputcol->text() == "")
        ui->error->setText("Error en el numero de columnas");
}
*/
bool MainWindow::on_simular_clicked()
{

    //QMessageBox::critical(this,"Infor", "mesa");
    if(ui->inputfilas->text() == ""){
        criticalerror("Error en las filas", "Introduce un número de filas > 1 ");
    }else
        if(ui->inputcol->text() == ""){
            criticalerror("Error en las columnas", "Introduce un número de columnas > 1 ");
        }else{
            //informationerror("", "¡Correcto!");

            config.row_number = ui->inputfilas->text().toInt();
            config.col_number = ui->inputcol->text().toInt();
            config.block_number = ui->inputobs->text().toInt();


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
