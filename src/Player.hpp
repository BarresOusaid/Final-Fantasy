#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"
#include "TileMap.hpp"
#include "Input.hpp"
#include "State.hpp"

class Player : public TileMap {

public:
		
	Player();
    Player(int i, int j, std::string s);
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
    void moveCharacterSprite(Input *playerInput);
    void moveCharacterSprite_auto(int i);
    void moveIA(bool stop);
private:
    
    TileMap characterMap;
    int tileID[1];
    
};
#endif
