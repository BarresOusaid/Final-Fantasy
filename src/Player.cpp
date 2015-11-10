# include "Player.hpp"

Player::Player() {
	
	direction = SOUTH;
	stepDelay = 250.0;
	paused = 0;
	
	std::string textureNames = "../res/Characters/Benjamin.png";
	textures.loadFromFile(textureNames);
}	
