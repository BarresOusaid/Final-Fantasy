#include "State.hpp"


State::State() {
	player = 0;
	next = 0;
	prev = 0;

}

State::~State() 
{
}

void State::init(Player *p) {
	// initialise les ressources patagées
	player = p;
}


void State::processState(sf::Event &event) {
	// actualise un Input
	input.pollInput(event);
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

