#ifndef COLLISIONMANAGER__H
#define COLLISIONMANAGER__H

#include "Map.h"
#include "Player.h"

/// class CollisionManager - 
class CollisionManager {
  // Associations
  // Operations
public:
  static bool collidesWithPlayer (Player* player1, Player* player2);
  static bool collidesWithMap (Map* map);
};

#endif
