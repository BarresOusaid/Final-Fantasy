#include "Entity.hpp"
#include "TileMap.hpp"

class Map : public TileMap {

public:
		Map();
		~Map();
		
		enum Places
		{
			VILLAGE;
			DUNGEON;
			WORLD;
			PLACES
		}	
		
		void changeMap(Places place);
		
private:
		TileMap map_tile;
