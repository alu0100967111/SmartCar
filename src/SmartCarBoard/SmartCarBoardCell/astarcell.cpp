#include "astarcell.h"

AStarCell::AStarCell(int x_pos, int y_pos, int f_score, int g_score, int h_score):
  x_pos_(x_pos),
  y_pos_(y_pos),
  f_score_(f_score),
  g_score_(g_score),
  h_score_(h_score),
  start_(false),
  goal_(false),
  obstacle_(false),
  father_(NULL){} //TODO: Pass to smartpointer

AStarCell::AStarCell(const AStarCell &cell)
{
    *this = cell;
}

AStarCell::~AStarCell(){}

int AStarCell::get_f_score() const { return f_score_; }

int AStarCell::get_g_score() const { return g_score_; }

int AStarCell::get_h_score() const { return h_score_; }

int AStarCell::get_x_pos() const { return x_pos_; }

int AStarCell::get_y_pos() const { return y_pos_; }

std::pair<int, int> AStarCell::get_pos() const { return std::pair<int, int>(x_pos_, y_pos_); }

AStarCell* AStarCell::get_father() const { return father_; }

void AStarCell::set_f_score(int f_score)
{
  f_score_ = f_score;
}

void AStarCell::set_g_score(int g_score)
{
  g_score_ = g_score;
}

void AStarCell::set_h_score(int h_score)
{
  h_score_ = h_score;
}

void AStarCell::set_type(int type)
{
  switch (type) {
    case (0): start_ = true; break;
    case (1): goal_ = true; break;
    case (2): obstacle_ = true; break;
    default: break;
  }
}

void AStarCell::set_father(AStarCell* father)
{
  father_ = father;
}

bool AStarCell::operator< (const AStarCell& cell) const
{
  if (f_score_ != cell.get_f_score()) { return f_score_ < cell.get_f_score(); }
  else if (h_score_ != cell.get_h_score()) { return h_score_ < cell.get_h_score(); }
  else if (g_score_ != cell.get_g_score()) { return g_score_ < cell.get_g_score(); }
  else if (x_pos_ != cell.get_x_pos()) { return x_pos_ < cell.get_x_pos(); }
  else if (y_pos_ != cell.get_y_pos()) { return y_pos_ < cell.get_y_pos(); }
  else { return false; }
}

bool AStarCell::operator== (const AStarCell& cell) const
{
    if (x_pos_ != cell.x_pos_) { return false; }
    else if (y_pos_ != cell.y_pos_) { return false; }
    else { return true; }
}

bool AStarCell::operator!= (const AStarCell& cell) const
{
    return !(*this == cell);
}

const AStarCell& AStarCell::operator= (const AStarCell& cell)
{
  x_pos_ = cell.x_pos_;
  y_pos_ = cell.y_pos_;
  f_score_ = cell.f_score_;
  g_score_ = cell.g_score_;
  h_score_ = cell.h_score_;
  start_ = cell.start_;
  goal_ = cell.goal_;
  obstacle_ = cell.obstacle_;
  father_ = cell.father_; //OJO
}

std::ostream& operator<< (std::ostream& os, const AStarCell& cell)
{
    if (cell.start_) { os << "I"; }
    else if (cell.goal_) { os << "F"; }
    else if (cell.obstacle_) { os << "O"; }
    else { os << "."; }
}
