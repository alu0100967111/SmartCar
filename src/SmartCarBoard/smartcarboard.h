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
#include <QTime>

#include <SmartCarBoard/SmartCarBoardCell/astarcell.h>
#include "SmartCarBoard/SmartCarBoardCell/smartcarboardcell.h"
#include "SmartCarWindow/smartcarwindow.h"
#include <ui_smartcarwindow.h>
#include "Common/error.h"

using Position = std::pair<int, int>;   //PAREJA DE COORDENADAS
using Path = std::vector<Position>;     //VECTOR DE COORDENADAS
using AStarSet = std::set<AStarCell>;   //SET DE ASTARCELL
using AStarVector = std::vector<AStarCell>;     //VECTOR DE ASTARCELL
using AStarBoard = std::vector<AStarVector>;    //VECTOR DE VECTORES DE ASTARCELL

struct params {
    int row_number;
    int col_number;
    int block_number;
    int distance_algorithm;
};

struct size_struct {
    int width;
    int height;
};

class SmartCarBoard
{
public:
    SmartCarBoard(const struct params &config, const struct size_struct &frame_size, const bool &auto_,
                  Ui::SmartCarWindow &smart_car_window_ui);
    ~SmartCarBoard();

public slots:
    void slot_cell_clicked(int x_pos, int y_pos);

private:
    int row_number_;
    int column_number_;
    int block_number_;
    int distance_algorithm_;
    bool auto_;
    Ui::SmartCarWindow *smart_car_window_ui_;

    Position car_position_;
    Position goal_position_;
    std::set<Position> obstacle_positions_;

public:
    QVector<QVector<SmartCarBoardCell*> > smart_car_board_;
    Path AStar_Algorithm();
    //Para el boton start
    void set_block_number(const int);
    bool checkStart();

private:

    AStarBoard InitializeBoardAStar();
    int AStarDistance(AStarCell &current_cell);
    double AStarEstimateCost(AStarCell& neighbour_cell, AStarCell& goal);
    Path AStarReconstructPath(AStarCell* current_cell);

};

#endif // SMARTCARBOARD_H
