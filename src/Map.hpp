#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <string>
#include <fstream>
#include "TileMap.hpp"
#include "Player.hpp"
#include "MapState.hpp"

class MapState;
class Player;
class Map {
	public:
		Map();
		virtual ~Map();

		// initialisation de la map
		void init(Player *player, Input *input);	 
		void loadMap(std::string path);
		TileMap getMap();
		Player getPlayer();
		void popMap(int mapID, Map *m);
		Map *getNext() { return next; }
		Map *getPrev() { return prev; }
		void setNext(Map *map) { next = map; }
		void setPrev(Map *map) { prev = map; }
        void updateMap();
        void pauseMap();
        void unpauseMap();
        bool blockedTile(int x);
        int TileNumberConversion(int x,int y);
        int blockedTileID(int x);

        bool isEmpty(int x, int y);
    
	protected:
		
		TileMap map;
		Map *next, *prev;
		Player *myPlayer;
		Input *myInput;
        MapState *myMapState;
        int **tiles;
        int mapWidth, mapHeight, tileSize;
        int *tabMab = (int*) std::malloc(832*sizeof(int));
    
    /*virtual void init()=0;
    virtual void update()=0;
    virtual void pause()=0;
    virtual void unpause()=0;*/

};

#endif