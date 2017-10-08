#include "smartcarboardcell.h"
#include "smartcarboard.h"

SmartCarBoardCell::SmartCarBoardCell(SmartCarBoard *smart_car_board_in, const int x, const int y):
    smart_car_board(smart_car_board_in),
    x_position(x),
    y_position(y)
{
    this -> setFrameShape(QFrame::Box);
    this -> setFrameShadow(QFrame::Plain);
    this -> setLineWidth(5);

    this -> setMinimumSize(100,100);
    this -> setMaximumSize(100,100);
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
    smart_car_board->slot_cell_clicked(x_position,y_position);
}
