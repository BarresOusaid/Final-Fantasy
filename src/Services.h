#ifndef SERVICES__H
#define SERVICES__H

#include "Grid.h"
#include "DIRECTION.h"
#include "Player.h"

/// class Services - 
class Services {
  // Associations
  // Attributes
private:
  Grid grid;
  // Operations
public:
  int const getCellCount ();
  bool const findFree (int& x, int& y);
  int const countEmptyRec (int x, int y, int id);
  int countEmptyRecSub (int x, int y, int id, DIRECTION direction = NO);
  int const countEmptyIte (int x, int y, int id);
  int relax (int x, int y, int id, DIRECTION d);
  void ford (int x, int y, int id);
  void dijkstra (int x, int y, int id);
};

#endif
