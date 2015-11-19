#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include "Entity.hpp"
#include "Player.hpp"
#include "State.hpp"

class State;

class StateManager {

public:
	StateManager();
	~StateManager();
	
	//affiche et change un état
	void pushState(State *state);
	void popState();
	void changeState(State *state);
	void popAll();
	
	// actions des états
	void process(sf::Event &event);
	void update();
	
	// commence une partie
	void startGame();
	
private:
	// les personnages partagés par tout les états
	Player player;
	
	// head and tail of linked list of states
	// the linked list is treated like a stack
	State *head, *tail;

};
#endif
