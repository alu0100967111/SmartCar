#include "smartcarwindow.h"
#include "ui_smartcarwindow.h"

SmartCarWindow::SmartCarWindow(const struct params &config, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SmartCarWindow),
    smart_car_layout(new QGridLayout)
{
    ui->setupUi(this); // Configura la ventana ANTES

    // Cojo el ancho y el largo de la pantalla
    QRect screen = QApplication::desktop() -> screenGeometry();

    // Para que no se pueda redimensionar
    this -> setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    //this -> showMaximized();

    this -> smart_car_layout -> setHorizontalSpacing(0);
    this -> smart_car_layout -> setVerticalSpacing(0);

    // Ajusto las celdas de SmartCarBoard

    // Ver el mayor y ajustar segun formula tamaño del cuadrado.

    int width,height;

    if (config.row_number >= config.col_number) {
        height = (screen.height() - 100) / config.row_number; // (-200) Por la barra de herramientas
        width = height;
    }
    else {
        height = (screen.height() - 100) / config.col_number; // (-200) Por la barra de herramientas
        width = height;
    }


    while ( height*config.row_number < (screen.height() - 100) && height*config.col_number < screen.width() ) {
        height++;
    }

    width = height;

    screen_size_struct screen_size = { width, height };

    smart_car_board = new SmartCarBoard(config, screen_size);


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
            smart_car_layout->addWidget(smart_car_board->smart_car_board[i][j],i,j); // TODO: Poner privado...
        }
    }

    // Aqui es donde se debería ver tamaño widget, ponerlo cuadrado, borrar el layout y volverlo a poner bien
}
