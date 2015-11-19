#include "StateManager.hpp"

StateManager::StateManager() {
	
	head=0;
	tail=0;
	
}

StateManager::~StateManager() {
	
	popAll();	

}

void StateManager::pushState(State *state) {
	// affiche et initialise un nouvel état
	if (tail) {
		tail->pauseState();
		tail->setNextState(state);
	}
	state->setPreviousState(tail);
	tail = state;
	tail->init(&player, this);
}

void StateManager::popState() {
	// nettoie un état
	if (tail) {
		State *toPop = tail;
		tail = tail->getPreviousState();
		if (tail) {
			tail->unpauseState();
		}

		delete toPop;
		toPop = 0;
	}
}

void StateManager::changeState(State *state) {
	// pop the current state
	popState();

	// push the new state
	pushState(state);
}

void StateManager::popAll() {
	// pop any states
	while (tail) {
		popState();
	}
}
void StateManager::process(sf::Event &event) {
	tail->processState(event);
}

void StateManager::update() {
	tail->updateState();
}

/*void StateManager::startGame() {
	popAll();	// pop all current states

	// put party on world map
	MapState *ms = new MapState();
	pushState(ms);
	ms->pushMap(new World());
}*/
