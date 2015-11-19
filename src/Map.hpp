#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <fstream>
#include <sstream> 

#include "TileMap.hpp"
#include "MapState.hpp"
#include "Input.hpp"
#include "Player.hpp"

class Input;

class Map {
	public:
		Map();
		virtual ~Map();

		// initialisation de la map
		void init();

		//  une liste chainée pour permettre de gerer les états
		Map *getNext() { return next; }
		Map *getPrev() { return prev; }
		void setNext(Map *map) { next = map; }
		void setPrev(Map *map) { prev = map; }

		// handle map operations
		void updateMap();

		// pause/unpause map
		void pauseMap();
		void unpauseMap();
	
	protected:
		// each map has its own input
		Input *input;

		// every map inherits access to the party
		Player *player;

		// texture ids and count
		enum TexInfo {MAP, COUNT};


		// current width and height of window
		int windowWidth, windowHeight;	

		// parties current position on this map
		int currentX, currentY;

		// id of the map
		int mapID;

		// name of the region and map file
		std::string region;
		std::string mapFile;

		// array of info about map tiles
		int **tiles;
		
		// map dimensions, size of each tile
		int mapWidth, mapHeight, tileSize;

	private:
		 TileMap map;
		 Map *next, *prev;

	// menu operations
	virtual void update() = 0;
	virtual void render() = 0;

	virtual void pause() = 0;
	virtual void unpause() = 0;
};

#endif
