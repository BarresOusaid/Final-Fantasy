#include "State.hpp"


State::State() {
	// initialize opengl state
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);*/
	player = 0;

	next = 0;
	prev = 0;

}

State::~State() 
{
}

void State::init(Player *p, StateManager *sm) {
	
	// initialise les ressources patagées
	player = p;
	stateManager = sm;
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

