#include "State.hpp"


State::State() {
	player = 0;
	sm = 0;
	next = 0;
	prev = 0;

}

State::~State() 
{
}

void State::init(Player *p, StateManager *sm) {
	// initialise les ressources patagées
	player = p;
	sm = sm;
}


void State::processState(sf::Event &event) {
	// actualise un Input
	input.pollInput(event);
}

void State::updateState() {
	update();
}

State *State::getNextState()
{
	return next;
}


State *State::getPreviousState()
{
	return prev;
}

void State::setNextState(State *state)
{
	next = state;
}

void State::setPreviousState(State *state)
{
	prev = state;
}

void State::pauseState() {
	
	pause();

}

void State::unpauseState() {
	
	unpause();

}

