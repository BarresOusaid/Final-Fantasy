#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.hpp"
#include "Player.hpp"
#include "MapState.hpp"

class State;

class StateManager {
	public:
		StateManager();
		~StateManager();

		// push, pop or change states
		void pushState(State *state);
		void popState();
		void changeState(State *state);
		void popAll();

		// state actions
		void process(sf::Event &event);
		void update();
		//void render(int width, int height);

		// start the game
		void startGame();
	private:
		// players party, shared across states
		Player player;

		// head and tail of linked list of states
		// the linked list is treated like a stack
		State *head, *tail;
};

#endif
