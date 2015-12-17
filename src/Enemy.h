#ifndef ENEMY__H
#define ENEMY__H

#include "TileMap.h"
#include "Stats.h"
#include "Entity.h"

/// class Enemy - 		
class Enemy : public Entity {
  // Attributes
public:
  int tileID[1];
private:
  TileMap enemy;
  // Operations
public:
  Enemy ();
  ~Enemy ();
  void init (std::string name);
  void render (int x, int y);
  int act ();
  int getAttribute (Stats s);
private:
  TileMap getTileMap ();
};

#endif
