#ifndef MAP__H
#define MAP__H

#include "TileMap.h"
#include "Player.h"
#include "Input.h"
#include "DIRECTION.h"
#include "Type.h"

/// class Map - 
class Map {
  // Associations
  // Attributes
protected:
  TileMap map;
  Map* next;
  Map* prev;
  Player* myPlayer;
  Input* myInput;
  int** tiles;
  int mapWidth;
  int mapHeight;
  int tileSize;
  int* tabMap;
  int x;
  int y;
  int* metaData;
  // Operations
public:
  Map ();
  ~Map ();
  void init (Player* player, Input* input);
  void loadMap (std::string path);
  TileMap getMap ();
  Player getPlayer ();
  Input getInput ();
  void popMap (int mapID, Map* m);
  int* const getTabMap ();
  Map* getNext ();
  Map* getPrev ();
  void setNext (Map* map);
  void setPrev (Map* map);
  int TileNumberConversion (int x, int y);
  int autorisedTileID (int x);
  bool isEmpty (int x, int y);
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
