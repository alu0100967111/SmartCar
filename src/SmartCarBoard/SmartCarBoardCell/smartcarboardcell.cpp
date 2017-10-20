#include "SmartCarBoard/SmartCarBoardCell/smartcarboardcell.h"
#include "SmartCarBoard/smartcarboard.h"

SmartCarBoardCell::SmartCarBoardCell(SmartCarBoard* smart_car_board_in, const struct size_struct &frame_size, int x_pos, int y_pos):
  smart_car_board(smart_car_board_in),
  x_pos_(x_pos),
  y_pos_(y_pos),
  car_(false),
  goal_(false),
  obstacle_(false)
{
    // Opciones de diseño
    this -> setFrameShape(QFrame::Box);
    this -> setFrameShadow(QFrame::Plain);
    this -> setLineWidth(2);

    this -> setMinimumSize(frame_size.height,frame_size.width);
    this -> setMaximumSize(frame_size.height,frame_size.width);
    this -> setScaledContents(true);

    connect(this, SIGNAL (cell_clicked()), this, SLOT (slot_cell_clicked()));
}

SmartCarBoardCell::~SmartCarBoardCell() {}

bool SmartCarBoardCell::event(QEvent* event)
{
    if(event->type() == QEvent :: MouseButtonRelease) { // Identify Mouse press Event
        qDebug() << "Got Mouse Event";
        emit cell_clicked();
    }

    return QWidget::event(event);
}

void SmartCarBoardCell::slot_cell_clicked()
{
    smart_car_board->slot_cell_clicked(x_pos_,y_pos_);
}

int SmartCarBoardCell::get_x_pos() { return x_pos_; }

int SmartCarBoardCell::get_y_pos() { return y_pos_; }

bool SmartCarBoardCell::is_car() { return car_; }

bool SmartCarBoardCell::is_goal() { return goal_; }

bool SmartCarBoardCell::is_obstacle() { return obstacle_; }

void SmartCarBoardCell::set_car() {
    this -> setPixmap(QPixmap("../photos/car.png").scaled(this->width(),this->height(),Qt::KeepAspectRatio));
    car_ = true;
}

void SmartCarBoardCell::set_goal() {
    this -> setPixmap(QPixmap("../photos/goal.png").scaled(this->width(),this->height(),Qt::KeepAspectRatio));
    goal_ = true;
}

void SmartCarBoardCell::set_obstacle() {
    this -> setStyleSheet("background-color:black;");
    obstacle_ = true;
}
