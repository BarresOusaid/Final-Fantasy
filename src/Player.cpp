#include "Services.hpp"
#include "Grid.hpp"
#include "Player.hpp"
#include "Grid.hpp"
#include "Map.hpp"

using namespace sf;
using namespace std;

int i_down = 0;
int i_up = 0;
int i_left = 0;
int i_right = 0;

Player::Player() {
    
    tileID[0] = {1};
    characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
    characterMap.setPosition(224, 224);
    //characterMap.setScale(2, 2);

}

Player::Player(int i, int j, std::string s) {
    
    tileID[0] = {1};
    if(s=="Hero")
    {
        characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
    }
    if(s=="Enemy")
    {
        characterMap.load("../res/Enemies/Enemies.png", sf::Vector2u(35, 35), tileID, 1, 1);
    }
    characterMap.setPosition(i*200, j*200);
    //characterMap.setScale(2, 2);
}

Player::~Player() {

}

void Player::moveCharacterSprite(DIRECTION direct)
{
	characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
	if(direct == HAUT)
	{
		i_up++;
		if(i_up%2==0)
		{
			tileID[0] = {9};
		}
		if(i_up%2==1)
		{
			tileID[0] = {11};
		}
			
            characterMap.move(0, -32);
        
	}
   
	if(direct == BAS)
	{
      
		i_down++;
		if(i_down%2==0)
		{
			tileID[0] = {0};
		}
		if(i_down%2==1)
		{
			tileID[0] = {2};
		}
        
            characterMap.move(0, 32);
        
	}
	
	if(direct == GAUCHE)
	{
       
		i_left++;
		if(i_left%2==0)
		{
			tileID[0] = {3};
		}
		if(i_left%2==1)
		{
			tileID[0] = {5};
		}
       
            characterMap.move(-32, 0);
        
	}
	
	if(direct == DROITE)
	{
      
		i_right++;
		if(i_right%2==0)
		{
			tileID[0] = {6};
		}
		if(i_right%2==1)
		{
			tileID[0] = {8};
		}
        
        
            characterMap.move(32, 0);
        
	}
}



void Player::moveCharacterSprite_auto(int i, int x, int y)
{
    characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
    
        if(i==1)
        {
        characterMap.move(0, -y);
        }
    
        if(i==2)
        {
        characterMap.move(0, y);
        }
        if(i==3)
        {
        characterMap.move(-x, 0);
        }
        if(i==4)
        {
        characterMap.move(x, 0);
        }
        if(i==5)
        {
            characterMap.move(1,1);
        }
}


/*
void Player::moveCharacterSprite_IA(Services service){
   
}*/

TileMap Player::getTileMap()
{
    return characterMap;
}

/*Input Player::getInput()
{
	return playerInput;
}*/



