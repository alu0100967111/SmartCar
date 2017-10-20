#include "smartcarboard.h"

SmartCarBoard::SmartCarBoard(const struct params &config,const struct size_struct &frame_size):
    row_number_(config.row_number),
    column_number_(config.col_number),
    is_car_(false),
    is_goal_(false),
    block_number_(config.block_number)
{

    // Inicializamos Tablero

    for (int i = 0; i < row_number_; ++i) {
        QVector<SmartCarBoardCell*> label_row;
        for (int j = 0; j < column_number_; ++j) {
            label_row.push_back(new SmartCarBoardCell(this, frame_size, i, j));
        }
        smart_car_board_.push_back(label_row);
    }
}

SmartCarBoard::~SmartCarBoard()
{}

void SmartCarBoard::slot_cell_clicked(int i, int j)
{
    if (!is_car_) {
        qDebug() << "It's the car";
        smart_car_board_[i][j] -> set_car();
        is_car_ = true;
    }
    else if (!is_goal_) {
        qDebug() << "It's the goal";
        smart_car_board_[i][j] -> set_goal();
        is_goal_ = true;
    }
    else if (block_number_ > 0 ) { // Si es un bloque, que sea menor que numero de bloques
        qDebug() << "It's a block";
        smart_car_board_[i][j] -> set_obstacle();
        block_number_--;
    }
}

