#ifndef GRID__H
#define GRID__H

#include "DIRECTION.h"

/// class Grid - 
class Grid {
  // Attributes
public:
  int metaData[];
private:
  int width;
  int height;
  int grid[32][26];
  int x;
  int y;
  Map* mapGrid;
  // Operations
public:
  Grid ();
  ~Grid ();
   int const getWidth ();
  int const getHeight ();
  bool const isValid (int x, int y, DIRECTION d = NO);
  bool const updateCoords (int& x, int& y, DIRECTION d = NO);
  Type const getType (int x, int y, DIRECTION d = NO);
  int const getMetaData (int x, int y, int id, DIRECTION d = NO);
  void setMetaData (int x, int y, int id, int value, DIRECTION d = NO);
  void initMetaData (int id, int value);
};

#endif
