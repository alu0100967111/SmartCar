#include "smartcarboard.h"

SmartCarBoard::SmartCarBoard(const struct params &config, const struct screen_size_struct &screen):
    row_number(config.row_number),
    column_number(config.col_number),
    is_car(false),
    is_aim(false),
    block_number(config.block_number)
{
    // Inicializamos Tablero

    for (int i = 0; i < row_number; ++i) {
        QVector<SmartCarBoardCell*> label_row;
        for (int j = 0; j < column_number; ++j){
            label_row.push_back(new SmartCarBoardCell(this, i, j, screen));
        }
        smart_car_board.push_back(label_row);
    }
}

SmartCarBoard::~SmartCarBoard()
{}

void SmartCarBoard::ResizeCells() {

    qDebug() << smart_car_board[0][0]->width();
    qDebug() << "x";
    qDebug() << smart_car_board[0][0]->height();

    int cell_width = smart_car_board[0][0] -> width();
    int cell_height = smart_car_board[0][0] -> height();

    if (cell_width > cell_height) {
        cell_width = cell_height;
    }
    else if (cell_width < cell_height) {
        cell_height = cell_width;
    }

    for (int i = 0; i < row_number; ++i) {
        for (int j = 0; j < column_number; ++j) {
            smart_car_board[i][j]->setFixedSize(cell_width,cell_height);
        }
    }
}

void SmartCarBoard::slot_cell_clicked(int i, int j)
{
    qDebug() << smart_car_board[i][j]->width();
    qDebug() << "x";
    qDebug() << smart_car_board[i][j]->height();

    int pixmap_width = smart_car_board[i][j]->width();
    int pixmap_height = smart_car_board[i][j]->height();

    if (!is_car) {
        qDebug() << "It's a car";
        smart_car_board[i][j] -> setPixmap(QPixmap("../photos/car.png").scaled(pixmap_width,pixmap_height,Qt::KeepAspectRatio));
        is_car = true;
    }
    else if (!is_aim) {
        qDebug() << "It's the aim";
        smart_car_board[i][j] -> setPixmap(QPixmap("../photos/aim.png").scaled(pixmap_width,pixmap_height,Qt::KeepAspectRatio));
        is_aim = true;
    }
    else if (block_number > 0 ){ // Si es un bloque, que sea menor que numero de bloques
        qDebug() << "It's a block";

        smart_car_board[i][j]->setStyleSheet("background-color:black;");

        block_number--;
    }
}
