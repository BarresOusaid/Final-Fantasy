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
    

    TileMap getTileMap();
    void moveCharacterSprite(DIRECTION::DIRECTION direct);
    void moveCharacterSprite_auto(int i);
    void moveCharacterSprite_IA();

private:
    
    TileMap characterMap;
    int tileID[1];
    
};
#endif
