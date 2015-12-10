#ifndef MAP__H
#define MAP__H

#include "TileMap.h"
#include "Player.h"
#include "Input.h"

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
  Map* getNext ();
  Map* getPrev ();
  void setNext (Map* map);
  void setPrev (Map* map);
  int TileNumberConversion (int x, int y);
  int autorisedTileID (int x);
  bool isEmpty (int x, int y);
};

#endif
