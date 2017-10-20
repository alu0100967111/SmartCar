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
    explicit SmartCarBoardCell(SmartCarBoard* smart_car_board_in, const struct size_struct &frame_size, int x_pos, int y_pos);
    virtual ~SmartCarBoardCell();

    int get_x_pos();
    int get_y_pos();
    bool is_car();
    bool is_goal();
    bool is_obstacle();

    void set_car();
    void set_goal();
    void set_obstacle();

signals:
    void cell_clicked();

public slots:
    void slot_cell_clicked();

protected:
    bool event(QEvent* event);

    SmartCarBoard* smart_car_board;
    int x_pos_;
    int y_pos_;
    bool car_; // Start
    bool goal_;
    bool obstacle_;

};

#endif // SMARTCARBOARDCELL_H
