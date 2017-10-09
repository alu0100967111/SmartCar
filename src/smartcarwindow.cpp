#include "smartcarwindow.h"
#include "ui_smartcarwindow.h"

SmartCarWindow::SmartCarWindow(const struct params &config, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SmartCarWindow),
    smart_car_layout(new QGridLayout),
    smart_car_board(config)
{
    ui->setupUi(this); // Configura la ventana ANTES

    // Cojo el ancho y el largo de la pantalla
    QRect screen = QApplication::desktop() -> screenGeometry();
    this -> setMaximumSize(screen.width(), screen.height());
    this -> setMinimumSize(screen.width(), screen.height());

    // Para que no se pueda redimensionar
    this -> setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    // Ajusto las celdas de SmartCarBoard

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

    // Aqui es donde se debería ver tamaño widget, ponerlo cuadrado, borrar el layout y volverlo a poner bien
}
