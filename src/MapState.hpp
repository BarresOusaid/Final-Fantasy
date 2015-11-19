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

	private:
		// operations
		void update();

		// pause/unpause menu
		void pause();
		void unpause();

		// head and tail of linked list of maps
		// the linked list is treated like a stack
		Map *head, *tail;
};

#endif
