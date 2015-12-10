//
//  CollisionManager.cpp
//  Final-Mystic-Quest
//
//  Created by Sandoche on 01/12/15.
//  Copyright © 2015 My Organisation Name. All rights reserved.
//

#include "CollisionManager.hpp"


bool CollisionManager::collidesWithPlayer(Player *player1, Player *player2)
{
    int boundx, boundy, boundsx, boundsy;
    
    boundx=player1->getTileMap().getPosition().x;
    boundy=player1->getTileMap().getPosition().y;
    boundsx=player2->getTileMap().getPosition().x;
    boundsy=player2->getTileMap().getPosition().y;
    
    if((boundx<=boundsx+32)&&(boundsx-32<=boundx)&&((boundy<=boundsy+32)&&(boundsy-32<=boundy)))
    {
        return true;
    }
    else
    
    return false;
}

bool CollisionManager::collidesWithMap(Map *map)
{
	if(map->autorisedTileID(map->TileNumberConversion(map->getPlayer().getTileMap().getPosition().x, map->getPlayer().getTileMap().getPosition().y))==2
    || map->autorisedTileID(map->TileNumberConversion(map->getPlayer().getTileMap().getPosition().x, map->getPlayer().getTileMap().getPosition().y))==111
    || map->autorisedTileID(map->TileNumberConversion(map->getPlayer().getTileMap().getPosition().x, map->getPlayer().getTileMap().getPosition().y))==107
    || map->autorisedTileID(map->TileNumberConversion(map->getPlayer().getTileMap().getPosition().x, map->getPlayer().getTileMap().getPosition().y))==106
    || map->autorisedTileID(map->TileNumberConversion(map->getPlayer().getTileMap().getPosition().x, map->getPlayer().getTileMap().getPosition().y))==0)
	{
		return true;
	}

	else return false;
}		    



