#ifndef STATE_H
#define STATE_H

#include "Player.hpp"
#include "Input.hpp"

class Player;
class StateManager;

class State {
	
public:
	State();
	~State();
	
	void init(Player *p, StateManager *sm);

	
	State *getNextState();
	State *getPreviousState();
	
	void setNextState(State *state);
	void setPreviousState(State *state);
	
	// s'occupe des opérations sur les états
	void processState(sf::Event &event);
	void updateState();
	
	// pause un état
	void pauseState();
	void unpauseState();
	

protected:
	
	// chaque état à son propre input
	Input input;

	// chaque états partage les mêmes personnages
	Player *player;

	// states can push/pop/change state stack
	//ajouter un state manager
	StateManager *sm;

	// états précédant et suivant
	State *next, *prev;
		
	
private:

	// opération sur les états
	virtual void update() = 0;
	virtual void render() = 0;

	// pause et unpause()
	virtual void pause() = 0;
	virtual void unpause() = 0;		
};
#endif
