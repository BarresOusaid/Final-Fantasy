#include "Player.hpp"


using namespace sf;

int i_down = 0;
int i_up = 0;
int i_left = 0;
int i_right = 0;

Player::Player() {
    
    tileID[0] = {1};
    characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
    characterMap.setPosition(200, 200);
    characterMap.setScale(2, 2);

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
    characterMap.setScale(2, 2);
}

Player::~Player() {

}

void Player::moveCharacterSprite(Input *playerInput)
{
	characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
	if(playerInput->upPressed()==1)
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
        
            characterMap.move(0, -10);
        
	}
   
	if(playerInput->downPressed()==1)
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
        
            characterMap.move(0, 10);
        
	}
	
	if(playerInput->leftPressed()==1)
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
       
            characterMap.move(-10, 0);
        
	}
	
	if(playerInput->rightPressed()==1)
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
        
        
            characterMap.move(10, 0);
        
	}
}

void Player::moveCharacterSprite_auto(int i)
{
    characterMap.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), tileID, 1, 1);
    
        if(i==1)
        {i_up++;
            if(i_up%2==0)
            {
                 tileID[0] = {9};
            }
             if(i_up%2==1)
            {
                tileID[0] = {11};
            }
        characterMap.move(0, -10);
        }
    
        if(i==2)
        {i_down++;
            if(i_down%2==0)
            {
                tileID[0] = {0};
            }
            if(i_down%2==1)
            {
                tileID[0] = {2};
            }
            characterMap.move(0, 10);
        }

        if(i==3)
        {i_left++;
            if(i_left%2==0)
            {
                tileID[0] = {3};
            }
            if(i_left%2==1)
            {
                tileID[0] = {5};
            }
            characterMap.move(-10, 0);
        }

        if(i==4)
        {i_right++;
            if(i_right%2==0)
            {
                tileID[0] = {6};
            }
            if(i_right%2==1)
            {
                tileID[0] = {8};
            }
            characterMap.move(10, 0);
        }
}



TileMap Player::getTileMap()
{
    return characterMap;
}

/*Input Player::getInput()
{
	return playerInput;
}*/

void Player::moveIA(bool stop){
    Input *in = new Input();
    
    if (stop){
        in -> upPressed();
        moveCharacterSprite(in);
        if(stop){
            in -> rightPressed();
            moveCharacterSprite(in);
            if(stop){
                in -> leftPressed();
                moveCharacterSprite(in);
                if(stop){
                    in -> downPressed();
                    moveCharacterSprite(in);
                }
                else {
                    in -> rightPressed();
                    moveCharacterSprite(in);
                }
            }
            else {
                in -> downPressed();
                moveCharacterSprite(in);
            }
        }
        else {
            in -> upPressed();
            moveCharacterSprite(in);
        }       
    }
    else {
        in -> leftPressed();
        moveCharacterSprite(in);
    }
}

