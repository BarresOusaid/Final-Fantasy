#include "Player.hpp"

using namespace sf;

Player::Player() {
    
    tileID[0] = {0};
    characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
    characterMap.setPosition(200, 200);
    characterMap.setScale(0.7, 0.7);

}

Player::~Player() {

}

void Player::changeCharacterSpriteDirection(int directionID)
{
    tileID[0] = {(char) directionID};
    characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
}

void Player::moveCharacterSprite (Directions direction)
{

    switch (direction)
    {
        case SOUTH:
            characterMap.move(0, 3);
            break;
        
        case NORTH:
            characterMap.move(0, -3);
            break;
            
        case WEST:
            characterMap.move(-3, 0);
            break;
            
        case EAST:
            characterMap.move(3, 0);
            break;
            
        default:
            break;
        
    }
}

TileMap Player::getTileMap()
{
    return characterMap;
}



