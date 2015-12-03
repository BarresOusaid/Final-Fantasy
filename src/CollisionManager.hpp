//
//  CollisionManager.hpp
//  Final-Mystic-Quest
//
//  Created by Sandoche on 01/12/15.
//  Copyright © 2015 My Organisation Name. All rights reserved.
//

#ifndef CollisionManager_hpp
#define CollisionManager_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "Player.hpp"
#include "Map.hpp"

class CollisionManager
{

public:
   
    static bool collidesWithPlayer(Player *player1, Player *player2);
    static bool collidesWithMap(Player *player, Map *map);
    
private:
};


#endif /* CollisionManager_hpp */

