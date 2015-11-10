#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"

class Player : public Entity {

public:
		
	Player();
	~Player();
		
	// les différents personnages de l'équipe	
	enum Characters
	{
		FIRST,
		SECOND,
		THIRD,
		FOURTH,
		SIZE
	};
	
	// les différentes directions des personnages
	enum Directions
	{
		NORTH,
		EAST,
		SOUTH, 
		WEST,
		DIRECTIONS
	};
	
	static const int INVENTORY_SIZE = 256;
	
	// le personnage active
	void setActive(int character);
	//Characters getActive();
	
	// pause le personnage
	/*void pause();
	void unpause();
	bool isPaused();*/
	
	// position du personnage
	int getX();
	int getY();
	void setX(int updateX);
	void setY(int updateY);
	
	// récupère la position exacte du personnage même durant la marche
	float getX(int titleSize);
	float getY(int titleSize);
	
	// direction vers laquel le personnage est orienté
	void setDirection(int dir);
	Directions getDirection();
	
	// marche dans la direction avec un intervalle de stepDelay
	void startStep(unsigned int s);
	bool stepping();
	void setStepDelay(float delay);
	
	// map en cours
	int getMap();
	void setMap(int mapID);
	std::string getRegion();
	void setRegion(std::string name);	


private:

		// Id de la texture et count
		enum TexInfo 
		{
			CHARMAPSPRITES, 
			TEXTURECOUNT
		};
		sf::Texture textures;

		// le personnage active
		Characters active;

		// map et le personnage en (x, y)
		int map, x, y;
		std::string region;

		// quelle direction le personnage fait face
		Directions direction;

		// pause le personnage
		bool paused;

		// clignote dès que le personnage fait un pas
		unsigned int step;	// 0 si il ne marche pas

		// temps nécessaire pour faire un pas
		float stepDelay;

		// finir de faire un pas de distance tileSize
		void stopStep(int tileSize);

		// largent de l'équipe
		unsigned int gil;

		// party inventory
		int items[INVENTORY_SIZE];

		// item counts in seperate array
		// to quickly check if party has a specific item
		int itemCount[INVENTORY_SIZE];

		// ticks played, ticks at last update
		unsigned int ticksPlayed, ticksUpdate;
		sf::Time time;

};
#endif
