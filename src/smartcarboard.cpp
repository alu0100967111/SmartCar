#include "smartcarboard.h"

SmartCarBoard::SmartCarBoard(const int row, const int column):
    row_number(row),
    column_number(column),
    is_car(false),
    is_aim(false),
    block_number(5)
{
    // Inicializamos Tablero

    for (int i = 0; i < row; ++i) {
        QVector<SmartCarBoardCell*> label_row;
        for (int j = 0; j < column; ++j){
            label_row.push_back(new SmartCarBoardCell(this, i, j));
        }
        smart_car_board.push_back(label_row);
    }
}

SmartCarBoard::~SmartCarBoard()
{}

void SmartCarBoard::slot_cell_clicked(int i, int j)
{
    if (!is_car) {
        qDebug() << "It's a car";
        smart_car_board[i][j] -> setPixmap(QPixmap("../photos/car.png"));
        is_car = true;
    }
    else if (!is_aim) {
        qDebug() << "It's the aim";
        smart_car_board[i][j] -> setPixmap(QPixmap("../photos/aim.png"));
        is_aim = true;
    }
    else if (block_number > 0 ){ // Si es un bloque, que sea menor que numero de bloques
        qDebug() << "It's a block";

        smart_car_board[i][j]->setStyleSheet("background-color:black;");

        block_number--;
    }
}
