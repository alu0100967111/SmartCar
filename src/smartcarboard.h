#ifndef SMARTCARBOARD_H
#define SMARTCARBOARD_H

#include <QVector>

#include <smartcarboardcell.h>

class SmartCarBoard
{
public:
    SmartCarBoard(const int row, const int column);
    ~SmartCarBoard();

public slots:
    void slot_cell_clicked(int i, int j);

private:
    int row_number;
    int column_number;
    int block_number;
    bool is_car;
    bool is_aim;

public:
    QVector<QVector<SmartCarBoardCell*>> smart_car_board;
};

#endif // SMARTCARBOARD_H
