#ifndef ASTARCELL_H
#define ASTARCELL_H

#include <climits>
#include <iostream>
#include <sstream>

class AStarCell
{

public: // TEMP
    bool start_;
    bool goal_;
    bool obstacle_;

private:
  // Current Position
  int x_pos_;
  int y_pos_;

  int f_score_; // For each node, the total cost of getting to the goal by passing that node. It's partly heuristic.
  int g_score_; // For each node, the cost of getting from the start node to that node.
  int h_score_; // For each node, the heuristic distance to get to the goal. Only used in comparations.
  AStarCell* father_; // Where came from

public:

  // Constructor & Destructor
  AStarCell(int x_pos = 0, int y_pos = 0, int g_score = INT_MAX, int f_score = INT_MAX, int h_score = INT_MAX); // Tipo = -1->Normal, 0->Inicial, 1->Final, 2->Obstáculo.
  AStarCell(const AStarCell& cell);
  ~AStarCell();

  // Setters
  int get_f_score() const;
  int get_g_score() const;
  int get_h_score() const;
  int get_x_pos() const;
  int get_y_pos() const;
  std::pair<int, int> get_pos() const;
  AStarCell* get_father() const;

  // Getters
  void set_f_score(int f_score);
  void set_g_score(int g_score);
  void set_h_score(int h_score);
  void set_type(int type);
  void set_father(AStarCell* father);

  // Overload Operators
  bool operator< (const AStarCell& cell) const;
  bool operator== (const AStarCell& cell) const;
  bool operator!= (const AStarCell& cell) const;
  const AStarCell& operator= (const AStarCell& cell);

  friend std::ostream& operator<< (std::ostream& os, const AStarCell& cell);

};

#endif // ASTARCELL_H
