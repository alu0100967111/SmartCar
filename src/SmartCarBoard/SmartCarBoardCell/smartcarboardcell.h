#ifndef SMARTCARBOARDCELL_H
#define SMARTCARBOARDCELL_H

#include <Qt>
#include <QEvent>
#include <QDebug>
#include <QLabel>
#include <QFrame>

class SmartCarBoard;

class SmartCarBoardCell : public QLabel
{
    Q_OBJECT

public:
    explicit SmartCarBoardCell(SmartCarBoard* smart_car_board_in, const int x, const int y, const struct size_struct &frame_size);
    virtual ~SmartCarBoardCell();

signals:
    void cell_clicked();

public slots:
    void slot_cell_clicked();

protected:
    bool event(QEvent* event);

    SmartCarBoard* smart_car_board;
    int x_position;
    int y_position;
    int ancho;

};

#endif // SMARTCARBOARDCELL_H
