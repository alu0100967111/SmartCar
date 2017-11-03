#include "smartcarboard.h"

//CONSTRUCTOR: Crea una matriz de <SmartCarBoardCell> en smart_car_board_
//Si se ha seleccionado obstáculos automáticos, también los introduce
SmartCarBoard::SmartCarBoard(const struct params &config, const struct size_struct &frame_size, const bool &auto_):
    row_number_(config.row_number),
    column_number_(config.col_number),
    distance_algorithm_(config.distance_algorithm),
    car_position_(-1,-1),
    goal_position_(-1,-1),
    obstacle_positions_(),
    auto_(auto_),
    block_number_(config.block_number)
{
    // Inicializamos Tablero
    for (int i = 0; i < row_number_; ++i) { //Para cada fila
        QVector<SmartCarBoardCell*> label_row;
        for (int j = 0; j < column_number_; ++j) { //Añadir cada elemento de la columna
            label_row.push_back(new SmartCarBoardCell(this, frame_size, i, j));
        }
        smart_car_board_.push_back(label_row);
    }

    //Si está en automático, metemos los obstáculos
    if(auto_){
        //Inicializar qsrand para valores aleatorios
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());

        //Mientras queden bloques pendientes de poner, seguir intentando
        for(; block_number_ > 0; block_number_--){
            int x = qrand() % (row_number_);
            int y = qrand() % (column_number_);
            qDebug() << "It's an automated block" << x << " " << y;

            // ¿Si en esa posición ya hay un obstáculo?
            while (obstacle_positions_.count(Position(x, y)) != 0) {
               x = qrand() % (row_number_);
               y = qrand() % (column_number_);
            }

            obstacle_positions_.insert(Position(x, y));
            smart_car_board_[x][y] -> set_obstacle();
        }
        block_number_ = 0;
    }

    // Mostrar mensaje de elegir coche
    informationerror("PASO 1", "Posicionar coche.");
}

SmartCarBoard::~SmartCarBoard() {}

void SmartCarBoard::slot_cell_clicked(int x_pos, int y_pos)
{
    if (car_position_ == Position(-1, -1)) {
        qDebug() << "It's the car";
        car_position_ = Position(x_pos, y_pos);
        smart_car_board_[x_pos][y_pos] -> set_car();

        // Mostrar mensaje de elegir meta
        informationerror("PASO 2", "Posicionar meta.");
    }
    else if (goal_position_ == Position(-1, -1)) {
        qDebug() << "It's the goal";

        if (Position(x_pos, y_pos) == car_position_) {
           criticalerror("ERROR", "CELDA REPETIDA, ELIJA OTRA.");
        }
        else {
          goal_position_ = Position(x_pos, y_pos);
          smart_car_board_[x_pos][y_pos] -> set_goal();
        }
        if (block_number_ != 0) {
            informationerror("PASO 3", "Posicionar obstáculos.");
        }
    }
    else if (block_number_ > 0 ) { // Si es un bloque, que sea menor que numero de bloques
        qDebug() << "It's a block";
        obstacle_positions_.insert(Position(x_pos, y_pos));
        block_number_--;
        smart_car_board_[x_pos][y_pos] -> set_obstacle();
    }
    qApp->processEvents(); // Proceso eventos
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

    smart_car_board_[x_pos][y_pos] -> PaintCell("background-color:red;"); qApp->processEvents();

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
          smart_car_board_[neighbour_cell.get_x_pos()][neighbour_cell.get_y_pos()] -> PaintCell("background-color:green;"); qApp->processEvents();
        }
      }
    }
    QThread::msleep(200);
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
    double distance = 0;

    switch (distance_algorithm_) {
      case 1: // Euclidian Distance
        distance = (int)sqrt((x_distance * x_distance) + (y_distance * y_distance)) + 0.5;
        break;
      case 2: // Manhattan distance
        distance = abs(x_distance) + abs(y_distance);
        break;
      case 3: // Chebyshev distance
        distance = std::max(abs(x_distance), abs(y_distance));
        break;
      default:
        criticalerror("ERROR", "ERROR FATAL DISTANCIA");
        break;
    }

    return distance;
}

Path SmartCarBoard::AStarReconstructPath(AStarCell* current_cell)
{
    Path total_path;

    while (current_cell != NULL) {
       Position path_position = current_cell -> get_pos();
       total_path.push_back(path_position);

       current_cell = current_cell -> get_father();

       //Lo dibujamos
       if (total_path.size() != 1 && current_cell != NULL) {
           smart_car_board_[path_position.first][path_position.second] -> PaintCell("background-color:yellow;");
       }
    }

    for (int i = total_path.size()-1; i == 0 ; i--) {
        QThread::msleep(200);
        smart_car_board_[car_position_.first][car_position_.second] -> PaintCell("background-color:yellow;");
        car_position_ = total_path[i];
        smart_car_board_[car_position_.first][car_position_.second] -> setPixmap(QPixmap("../photos/car.png"));
        qApp->processEvents();
    }
    return total_path;
}

//Para el boton start
void SmartCarBoard::set_block_number(const int n){
    block_number_ = n;
}

bool SmartCarBoard::checkStart()
{
    if (car_position_ != Position(-1,-1) && goal_position_ != Position(-1,-1)) { return false; }
    return true;
}
