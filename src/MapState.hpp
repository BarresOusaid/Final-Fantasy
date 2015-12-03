#ifndef MAPSTATE_H
#define MAPSTATE_H

#include "State.hpp"
#include "Map.hpp"

class Map;

class MapState : public State {
	public:
		MapState();
		~MapState();

		// push, pop or change maps
		void pushMap(Map *map);
		void popMap();
		void changeMap(Map *map);

		// push BattleState on top of state stack
		// and return the new BattleState on top
		//BattleState *enterBattle(int battleID);
	private:
		// pause/unpause menu
		void pause();
		void unpause();

		void update(){}
		void render(){}

		// head and tail of linked list of maps
		// the linked list is treated like a stack
		Map *head, *tail;
};

#endif