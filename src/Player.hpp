#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"
#include "TileMap.hpp"
#include "Input.hpp"

#define NUMBER_OF_TILE 30

class Player : public TileMap {

public:
		
	Player();
	~Player();
    
    // les différentes directions des personnages
    enum Directions
    {
        NORTH,
        EAST,
        SOUTH,
        WEST,
        DIRECTIONS
    };
    
    TileMap getTileMap();
    void changeCharacterSpriteDirection(int i);
    void moveCharacterSprite (Directions direction);
    
private:
    
    TileMap characterMap;
    int tileID[1];
};
#endif
