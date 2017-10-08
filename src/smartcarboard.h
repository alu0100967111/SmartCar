#ifndef SMARTCARBOARD_H
#define SMARTCARBOARD_H

#include <QVector>

struct params;

#include <smartcarboardcell.h>

struct params{
    int row_number;
    int col_number;
    int block_number;
};

class SmartCarBoard
{
public:
    SmartCarBoard(const struct params &config);
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
