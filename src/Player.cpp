# include "Player.hpp"
using namespace sf;

Player::Player() {
	
	direction = SOUTH;
	stepDelay = 250.0;
	paused = 0;
	
	std::string textureNames = "../res/Characters/Benjamin.png";
	textures.loadFromFile(textureNames);
	
	active = FIRST;
}	

Player::~Player() {
}


void Player::setActive(int character) {
	
	if (character >= FIRST && character < SIZE) 
	{
		active = static_cast<Characters>(character);
	}

}

void Player::stopStep(int tileSize) {
	step = 0;	// finish step

	// update party position
	if (direction == NORTH) {
		y -= tileSize;
	} else if (direction == EAST) {
		x += tileSize;
	} else if (direction == SOUTH) {
		y += tileSize;
	} else {
		x -= tileSize;
	}
}

void Player::setX(int updateX) {
	step = 0;
	x = updateX;
}

void Player::setY(int updateY) {
	step = 0;
	y = updateY;
}

float Player::getX(int tileSize) {
	float xStepDistance = 0.0;

	const int stepTime = time.asMilliseconds () - step;
	if (step && stepTime < stepDelay) 
	{
		// if party is taking a step, smooth motion
		if (direction == EAST) 
		{
			xStepDistance = (stepTime / stepDelay) * tileSize;
		} else if (direction == WEST) 
		{
			xStepDistance = -(stepTime / stepDelay) * tileSize;
		}
	} else if (step) 
	{
		stopStep(tileSize);
	}
	return (x + xStepDistance);
}


float Player::getY(int tileSize) {
	float yStepDistance = 0.0;

	const int stepTime = time.asMilliseconds () - step;
	if (step && stepTime < stepDelay) {
		// if party is taking a step, smooth motion
		if (direction == NORTH) {
			yStepDistance = -(stepTime / stepDelay) * tileSize;
		} else if (direction == SOUTH) {
			yStepDistance = (stepTime / stepDelay) * tileSize;
		}
	} else if (step) {
		stopStep(tileSize);
	}
	return (y + yStepDistance);
}


void Player::setDirection(int dir) {
	if (dir < 0 || dir >= DIRECTIONS) {
		return;	// out of bounds
	}
	direction = static_cast<Directions>(dir);
}

// width and height of sprite sheet
	const float sheetWidth = 2860.0;
	const float sheetHeight = 1560.0;

// width of character on sprite sheet
	const float spriteWidth = 130;

