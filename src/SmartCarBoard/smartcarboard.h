#ifndef SMARTCARBOARD_H
#define SMARTCARBOARD_H

#include <QVector>

struct params;

#include "SmartCarBoard/SmartCarBoardCell/smartcarboardcell.h"
#include "Common/error.h"

struct params {
    int row_number;
    int col_number;
    int block_number;
};

struct size_struct {
    int width;
    int height;
};

class SmartCarBoard
{
public:
    SmartCarBoard(const struct params &config, const struct size_struct &frame_size);
    ~SmartCarBoard();

public slots:
    void slot_cell_clicked(int i, int j);

private:
    int row_number_;
    int column_number_;
    int block_number_;
    bool is_car_;
    bool is_goal_;

public:
    QVector<QVector<SmartCarBoardCell*> > smart_car_board_;
};

#endif // SMARTCARBOARD_H
