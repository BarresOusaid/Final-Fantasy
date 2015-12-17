#ifndef PLAYER__H
#define PLAYER__H

#include "TileMap.h"
#include "DIRECTION.h"
#include "Services.h"
#include "Entity.h"

/// class Player - 
class Player : public TileMap, public Entity {
  // Attributes
private:
  TileMap characterMap;
  int tileID[1];
  // Operations
public:
  Player ();
  ~Player ();
  Player (int xi, int yj, std::string s);
  TileMap getTileMap ();
  void moveCharacterSprite (DIRECTION direct);
  void moveCharacterSprite_auto (int i, int x , int y);
  void moveCharacterSprite_IA (Services service);
};

#endif
