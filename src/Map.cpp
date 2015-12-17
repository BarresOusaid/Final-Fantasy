#include "Services.hpp"
#include "Grid.hpp"
#include "Player.hpp"
#include "Grid.hpp"
#include "Map.hpp"

#include <string>
#include <fstream>

using namespace std;
using namespace sf;


Map::Map() {
    
    myInput=0;
    myPlayer=0;
    next=0;
    prev=0;
    tiles=0;

}

Map::~Map() {
    if (tiles) {
        int xTiles = mapWidth / tileSize;
        for (int i = 0; i < xTiles; i++) {
            delete[] tiles[i];
            tiles[i] = 0;
        }
        delete[] tiles;
        tiles = 0;
    }
}

void Map::init(Player *player, Input *input){
    myPlayer = player;
    myInput = input;
    //map.setScale(2, 2);
}



TileMap Map::getMap(){
    return map;
}

Player Map::getPlayer(){
    return *myPlayer;
}

Input Map::getInput(){
	return *myInput;
}	

void Map::loadMap(std::string path) {

    tabMap = (int*) std::malloc(832*sizeof(int));
	ifstream fichier(path, ios::in);

        int *adr;
        adr = tabMap;

        if(fichier)
        {
        
          while(fichier.eof()!=true){
            fichier >> *tabMap; 
            *tabMap = *(tabMap)++;
            }
        
           fichier.close();
        }

        else
           cerr << "Impossible d'ouvrir le fichier !" << endl;
            
           tabMap = adr;
        if (!map.load("../res/tileSet.png", Vector2u(32, 32), tabMap, 32, 26))
            cout << "erreur de load"<< endl;
    
    }

void Map::popMap(int mapID, Map *m) {
    
        switch(mapID)
        {
            case 1:
            m->loadMap("../res/map_Init");
            break;
            
            case 2:
            m->loadMap("../res/Map_Dungeon");
            break;
            
            default:
            m->loadMap("../res/Map_Battle");
            break;
        }
    }

int Map::autorisedTileID(int x) {
    
    return tabMap[x];
    
}

int Map::TileNumberConversion(int x,int y)
{
    int tileNumberx, tileNumbery;
    tileNumberx=x/32;
    tileNumbery=y/32;
    return (32*tileNumbery+tileNumberx);
}


bool Map::isEmpty(int x, int y){
    if( autorisedTileID(TileNumberConversion(x, y))==0 ||
        autorisedTileID(TileNumberConversion(x, y))==102 ||
        autorisedTileID(TileNumberConversion(x, y))==111 ||
        autorisedTileID(TileNumberConversion(x, y))==2 ||
        autorisedTileID(TileNumberConversion(x, y))==231)
    {
        return true;
    }

    else {
        return false;
    }
}

int* const Map::getTabMap (){
    return tabMap;
}