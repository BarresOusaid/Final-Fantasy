#ifndef ENEMY_H
#define ENEMY_H

#include <fstream>
#include <string>

#include "Entity.hpp"
#include "TileMap.hpp"


class Enemy : public Entity {
	public:
		Enemy();
		~Enemy();

		// initialize enemy
		void init(std::string name);

		// render enemy at (x, y)
		void render(int x, int y);

		// execute turn, return damage done
		int act();

		// get enemy attribute
		int getAttribute(Stats s);
		TileMap getTileMap();
	private:

		// enemy sprite texture
		TileMap enemy;
		int tileID[1] = {1};
};

#endif