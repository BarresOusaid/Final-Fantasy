#ifndef PLAYER__H
#define PLAYER__H

#include "TileMap.h"
#include "DIRECTION.h"
#include "Entity.h"
#include "Services.h"

/// class Player - 
class Player : public TileMap, public Entity {
  // Associations
  // Attributes
private:
  TileMap characterMap;
  int tileID[1];
  Services* service;
  // Operations
public:
  Player ();
  ~Player ();
  Player (int xi, int yj, std::string s);
  TileMap getTileMap ();
  void moveCharacterSprite (DIRECTION direct);
  void moveCharacterSprite_auto (int i, int x , int y);
  void moveCharacterSprite_IA (Map* map);
  int getX ();
  int getY ();
};

#endif
