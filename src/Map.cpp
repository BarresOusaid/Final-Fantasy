#include "Map.hpp"

Map::Map() {

}

Map::~Map() {
}

void Map::updateMap() {
    if (input->getStart()) {
        input->resetStart();

        // enter party menu from any
        // map when start button pressed
        return;
    }
    update();
}

void Map::init() {

    	// map filename containing map data
    	std::string mapData = "../res/map.txt";

    	std::ifstream mapfile;
    	mapfile.open(mapData.c_str());
      
        std::stringstream buffer; 
        // variable contenant l'intégralité du fichier 
            // copier l'intégralité du fichier dans le buffer 
        buffer << mapfile.rdbuf(); 
            // nous n'avons plus besoin du fichier ! 
        mapfile.close(); 
            // manipulations du buffer...
            std::string tmp = buffer.str();
            const char* cstr = tmp.c_str(); 
        std::cout << "Taille du buffer : " << cstr << '\n'; 

        if (!map.load("../res/tileSet.png", sf::Vector2u(32, 32), cstr, 16, 8))
            std::cout << "erreur de load"<< std::endl;
    }

void Map::pauseMap() {
    pause();
}

void Map::unpauseMap() {
    // restore party position
    //player->setX(currentX);
    //player->setY(currentY);

    // restore map name
    //player->setRegion(region);

    //unpause();

    std::cout <<"walou makhdamch"<< std::endl;
}
