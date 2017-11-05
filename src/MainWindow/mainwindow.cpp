#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    auto_(true),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
     //ui->inputobs->setPlaceholderText("% de obstáculos");
    //this->showMaximized();
    //ui->p_label->setVisible(false);// Set the status of the opposite
    ui->inputobs->setMaximum(90);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::get_block_conf(){
    return auto_;
}

void MainWindow::on_auto_checkbox_clicked()
{
    if(auto_ == false){
        ui->inputobs->setDisabled(false);
        auto_ = true;
    }else{
        ui->inputobs->setDisabled(true);
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
    }else {
       config.row_number = ui->inputfilas->text().toInt();
       config.col_number = ui->inputcol->text().toInt();
       config.block_number = ui->inputobs->value();
       config.distance_algorithm = ui -> heuristicOption -> currentIndex(); // Elegimos algoritmo Heurística

       //qDebug() << ui->inputobs->text().remove(QChar('%'), Qt::CaseInsensitive);

       if (auto_) { //Aleatorio
          /* n = filas m = columnas
           * nBloques = (n*m)*porcentaje/100;*/
          config.block_number = (ui->inputfilas->text().toFloat()*ui->inputcol->text().toFloat()) *
                  (ui->label_3->text().toFloat()/100);

          qDebug() << config.block_number;
       } else { //No aleatorio
          config.block_number = ui->label_3->text().toInt();
           config.block_number = 1000; //Para poner todos los obstaculos que queramos
       }

       SmartCarWindow* smart_car_window = new SmartCarWindow(config, auto_);
       smart_car_window->show();

       this->close();
       return true;
    }
    return false;
}

struct params MainWindow::get_params(){
    return config;
}
