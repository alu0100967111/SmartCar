#ifndef SMARTCARBOARD_H
#define SMARTCARBOARD_H

#include <QVector>
#include <Qt>
#include <QLabel>
#include <QFrame>
#include <QThread>
#include <QCoreApplication>

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

#include <SmartCarBoard/SmartCarBoardCell/astarcell.h>
#include "SmartCarBoard/SmartCarBoardCell/smartcarboardcell.h"
#include "Common/error.h"

using Position = std::pair<int, int>;
using Path = std::vector<Position>;
using AStarSet = std::set<AStarCell>; // SET PARA OPEN Y CLOSED
using AStarVector = std::vector<AStarCell>;
using AStarBoard = std::vector<AStarVector>; // TABLERO (VECTOR)

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
    void slot_cell_clicked(int x_pos, int y_pos);

private:
    int row_number_;
    int column_number_;
    int block_number_;

    Position car_position_;
    Position goal_position_;
    std::set<Position> obstacle_positions_;

public:
    QVector<QVector<SmartCarBoardCell*> > smart_car_board_;

private:
    Path AStar_Algorithm();
    AStarBoard InitializeBoardAStar();
    void PrintAStarBoard(const AStarBoard &board, const AStarSet &open_set, const AStarSet &closed_set);
    int AStarDistance(AStarCell &current_cell);
    double AStarEstimateCost(AStarCell& neighbour_cell, AStarCell& goal);
    Path AStarReconstructPath(AStarCell* current_cell);
};

#endif // SMARTCARBOARD_H
