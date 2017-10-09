#include "smartcarwindow.h"
#include "ui_smartcarwindow.h"

SmartCarWindow::SmartCarWindow(const struct params &config, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SmartCarWindow),
    smart_car_layout(new QGridLayout),
    smart_car_board(config)
{
    ui->setupUi(this); // Configura la ventana ANTES

    InicializeLayout(config.row_number,config.col_number);

    ui->SmartCarWidget->setLayout(smart_car_layout);
}

SmartCarWindow::~SmartCarWindow()
{
    delete ui;
}

void SmartCarWindow::InicializeLayout(const int row, const int column)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            smart_car_layout->addWidget(smart_car_board.smart_car_board[i][j],i,j); // TODO: Poner privado...
        }
    }
}
