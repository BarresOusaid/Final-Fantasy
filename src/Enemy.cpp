#include "Enemy.hpp"

Enemy::Enemy() {
}

Enemy::~Enemy() {
}

void Enemy::init(std::string name) {

	tileID[0]=1;

	setName(name);
	if (name == "0") {
		return;	// no enemy
	}

	std::ifstream in;
	in.open("res/data/" + name + ".data");

	// read in enemy attribute values
	int val;
	in >> val; attributes[HPMAX] = val;
			   attributes[HP] = val;
	in >> val; attributes[ATK]= val;
	in >> val; attributes[ACC] = val;
	in >> val; attributes[DEF] = val;
	in >> val; attributes[EVA] = val;
	in >> val; attributes[MDEF] = val;
	in >> val; attributes[EXP] = val;
	in >> val; attributes[GIL] = val;

	in.close();

	if (!enemy.load("../res/Enemies/monster_sprite_1.png", sf::Vector2u(32, 32), tileID, 1, 1))
   	std::cout << "erreur de load"<< std::endl;



	// dimensions of enemy on sprite sheet
	spriteDim = 192;
}

void Enemy::render(int x, int y) {
	if (getName() == "0") {
		return;	// no enemy to draw
	}

	renderx = x;
	rendery = y;

	enemy.move(renderx, rendery);

}

int Enemy::act() {
		// return attack damage, rand num from ATK to 2*ATK
		return (rand() % (attributes[ATK] + 1)) + attributes[ATK];
}

int Enemy::getAttribute(Stats s) {
	if (s >= LEVEL && s < STATSCOUNT) {
		return attributes[s];
	}
	return 0;
}

TileMap Enemy::getTileMap(){
	return enemy;
}
