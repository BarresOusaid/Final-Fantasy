#include "Map.hpp"

#include <string>
#include <fstream>

using namespace std;
using namespace sf;

/* -----------------------ERREUR-------------------------
Ereur a corriger dans setMetaData la ligne tiles[x][y] = metaData[id]; */


//********************ce qu'il faut faire************************
/*il faut deja que je cree une grille cad un tableau 2D qui me permettra de faire en sorte d'avoir un tableau
exploitable et puis le remplir avec le tablea tabMap ici il faut que j'initialise t[][] pour que ca marche
voila voila */


//*********************ce qui est fait*******************************
  /*je suis entrain de realiser l'IA mais jai un probleme de erreur de segmen donc le probleme vient de tiles 
  qui represete ma grille pour le moment mais elle est vide c'est pour cela cette merde ne marche pas*/

Map::Map() {
    
    myInput=0;
    myPlayer=0;
    next=0;
    prev=0;
    tiles=0;
    metaData =  new int [mapHeight*mapWidth];

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
    delete[] tabMap;
}

void Map::init(Player *player, Input *input){
    myPlayer = player;
    myInput = input;
    //map.setScale(2, 2);
}

int* const Map::getTabMap (){
    return tabMap;
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

  int const Map::getWidth (){
    return mapWidth;
  }

  int const Map::getHeight (){
    return mapHeight;
  }

  bool const Map::isValid (int x, int y, DIRECTION d){
    if (x < mapHeight && y < mapWidth){
        return true;
    }
    else 
        return false;
  }

  bool const Map::updateCoords (int& x, int& y, DIRECTION d){
    if (x < mapHeight && y < mapWidth){
      this -> x = x;
      this -> y = y;
        return true;
    }
    else 
        return false;
  }

  Type const Map::getType (int x, int y, DIRECTION d){
    if (isValid(x,y,d)){
           if (isEmpty(32*x,32*y)){
              return EmptySpace;
           }

           else {
            return FullSpace;
          }
    }
    else return Invalid;
  }
  
  void Map::initMetaData (int id, int value){
    //metaData[mapHeight*mapWidth];
    for (int i = 0; i < mapHeight*mapWidth; ++i)
    {
      metaData[i] = value;
    }
  }

  int const Map::getMetaData (int x, int y, int id, DIRECTION d){
    metaData[id] = autorisedTileID(TileNumberConversion(x, y));
    return metaData[id]; 
  }

  void Map::setMetaData (int x, int y, int id, int value, DIRECTION d){
     metaData[id] = value;
  }