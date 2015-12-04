#include "Map.hpp"

Map::Map() {
    
    myInput=0;
    myPlayer=0;
    myMapState=0;
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
    //myMapState = ms;
    //map.setScale(2, 2);
}


/*void Map::updateMap()
{
    update();
}

void Map::pauseMap()
{
    pause();
}

void Map::unpauseMap()
{
    unpause();
}*/

TileMap Map::getMap(){
    return map;
}

Player Map::getPlayer(){
    return *myPlayer;
}

void Map::loadMap(std::string path) {

 std::ifstream fichier(path, std::ios::in);

        int *adr;
        adr = tabMab;

        if(fichier)
        {
        
          while(fichier.eof()!=true){
            fichier >> *tabMab; 
            *tabMab = *(tabMab)++;
            }
        
           fichier.close();
        }

        else
           std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
            
           tabMab = adr;
        if (!map.load("../res/tileSet.png", sf::Vector2u(32, 32), tabMab, 32, 26))
            std::cout << "erreur de load"<< std::endl;
    
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

int Map::blockedTileID(int x) {
    
    return tabMab[x];
    
}

int Map::TileNumberConversion(int x,int y)
{
    int tileNumberx, tileNumbery;
    tileNumberx=x/32;
    tileNumbery=y/32;
    return (32*tileNumbery+tileNumberx);
}
