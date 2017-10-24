#include "smartcarboard.h"

SmartCarBoard::SmartCarBoard(const struct params &config,const struct size_struct &frame_size):
    row_number_(config.row_number),
    column_number_(config.col_number),
    car_position_(-1,-1),
    goal_position_(-1,-1),
    obstacle_positions_(),
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

SmartCarBoard::~SmartCarBoard() {}

void SmartCarBoard::slot_cell_clicked(int x_pos, int y_pos)
{
    if (car_position_ == Position(-1, -1)) {
        qDebug() << "It's the car";
        car_position_ = Position(x_pos, y_pos);
        smart_car_board_[x_pos][y_pos] -> set_car();
    }
    else if (goal_position_ == Position(-1, -1)) {
        qDebug() << "It's the goal";
        goal_position_ = Position(x_pos, y_pos);
        smart_car_board_[x_pos][y_pos] -> set_goal();
    }
    else if (block_number_ > 0 ) { // Si es un bloque, que sea menor que numero de bloques
        qDebug() << "It's a block";
        Path path;
        obstacle_positions_.insert(Position(x_pos, y_pos)); block_number_--;

        smart_car_board_[x_pos][y_pos] -> set_obstacle();
        qApp->processEvents(); // Proceso eventos

        if (block_number_ == 0) {
            QThread::sleep(2);
            path = AStar_Algorithm();

            // TODO: Si no hay camino?
            for ( auto x : path ) { std::cout << " { " << x.first << "," << x.second << " } ";}
            exit(1); // TODO: ¿Queremos esto?
        }
    }
}

Path SmartCarBoard::AStar_Algorithm()
{
  AStarBoard board = InitializeBoardAStar();
  AStarCell& start = board[car_position_.first][car_position_.second];
  AStarCell& goal = board[goal_position_.first][goal_position_.second];

  AStarSet closed_set = {};
  AStarSet open_set; open_set.insert(start);

  while (!open_set.empty()) {
    AStarCell current_cell = *(open_set.begin());
    if (current_cell == goal) { qDebug() << "Returning Path..."; return AStarReconstructPath(&current_cell); }

    int x_pos = current_cell.get_x_pos();
    int y_pos = current_cell.get_y_pos();

    closed_set.insert(current_cell);
    open_set.erase(open_set.begin());

    // Para las casillas de alrededor
    for (int i = -1; i <= 1; ++i) {
      for(int j = -1; j <= 1; ++j) {
        // Condiciones de siguiente iteración
        if (i == 0 && j == 0) continue; // Es nuestra posición
        if (x_pos+i < 0 || x_pos+i >= row_number_ || y_pos+j < 0 || y_pos+j >= column_number_) continue;

        AStarCell& neighbour_cell = board[x_pos+i][y_pos+j];
        if (neighbour_cell.obstacle_) continue;

        // Si NO está en la lista roja
        if (closed_set.count(neighbour_cell) == 0) {

          // Si es mayor no es un camino mejor. ¡Al inicial siempre es mejor! (MAX_INT)
          AStarCell *aux = board[x_pos][y_pos].get_father();
          neighbour_cell.set_father(&board[x_pos][y_pos]); // Para que funcione distancia

          int g_distance = AStarDistance(neighbour_cell);

          if (g_distance < neighbour_cell.get_g_score()) {
            neighbour_cell.set_g_score(g_distance);
            neighbour_cell.set_h_score(AStarEstimateCost(neighbour_cell, goal));
            neighbour_cell.set_f_score(neighbour_cell.get_g_score() + neighbour_cell.get_h_score());
          }
          else {
            neighbour_cell.set_father(aux);
          }

          //  Inserto la celda cambiada! Si ya estaba esa posicion la elimino

          AStarSet open_set_copy = open_set;
          for (auto cell: open_set) { //TODO: ¿Se podria cambiar este for modificacando el operador < de celda?
            if (cell.get_pos() == neighbour_cell.get_pos())
              open_set_copy.erase(cell);
          }
          open_set = open_set_copy;
          open_set.insert(neighbour_cell);
        }
      }
    }
        PrintAStarBoard(board, open_set, closed_set);
  }
  return {};
}

AStarBoard SmartCarBoard::InitializeBoardAStar()
{
    AStarBoard board = AStarBoard(row_number_, AStarVector(column_number_));

    for (int i = 0; i < row_number_; ++i) {
        for (int j = 0; j < column_number_; ++j) {
            if ( Position(i,j) == car_position_ ) {
                board[i][j] = AStarCell(i,j);
                board[i][j].set_g_score(0);
                board[i][j].set_type(0);
            }
            else if ( Position(i,j) == goal_position_ ) {
                board[i][j] = AStarCell(i,j);
                board[i][j].set_type(1);
                board[i][j].set_f_score(0);
            }
            else if ( obstacle_positions_.count(Position(i,j)) != 0 ) {
                board[i][j] = AStarCell(i,j);
                board[i][j].set_type(2);
            }
            else { board[i][j] = AStarCell(i,j); }
        }
    }
    return board;
}

int SmartCarBoard::AStarDistance(AStarCell& current_cell)
{
    AStarCell* current_cell_copy = &current_cell;

    int distance = 0, count= 0;

    while (!(current_cell_copy->start_) && (count < 10)) {
      count ++;
      distance += 10;
      current_cell_copy = current_cell_copy -> get_father();
    }

    return distance;
}

double SmartCarBoard::AStarEstimateCost(AStarCell& neighbour_cell, AStarCell& goal)
{
    int x_distance = (goal.get_x_pos() - neighbour_cell.get_x_pos())*10;
    int y_distance = (goal.get_y_pos() - neighbour_cell.get_y_pos())*10;

    // Euclidian Distance
    double distance = (int)sqrt((x_distance * x_distance) + (y_distance * y_distance)) + 0.5;

    // Manhattan distance
    //distance = abs(x_distance) + abs(y_distance);

    // Chebyshev distance
    //distance  =max(abs(x_distance), abs(y_distance));

    return distance;
}

void SmartCarBoard::PrintAStarBoard(const AStarBoard& board, const AStarSet& open_set, const AStarSet& closed_set)
{
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (open_set.find(board[i][j]) != open_set.end()) {
                if (board[i][j] == *open_set.begin()) { // Es el coche
                    //smart_car_board_[car_position_.first][car_position_.second] -> setPixmap(QPixmap("../photos/empty.png"));
                    //car_position_ = Position(i, j);
                    //smart_car_board_[i][j] -> set_car();
                }
                else { // Está en la verde
                    smart_car_board_[i][j] -> setStyleSheet("background-color:green;");
                }
            }
            else if (closed_set.find(board[i][j]) != closed_set.end()) {
                smart_car_board_[i][j] -> setStyleSheet("background-color:red;");
            }
        }
    }

    qApp->processEvents();
    QThread::msleep(200);
}

Path SmartCarBoard::AStarReconstructPath(AStarCell* current_cell)
{
    Path total_path;

    while (current_cell != NULL) {
       total_path.push_back(current_cell -> get_pos());
       current_cell = current_cell -> get_father();
    }

    return total_path;
}
