#include "Entity.hpp"


Entity::Entity() {
    
    //twenty.loadFromFile("../Final-Fantasy/Final-Mystic-Quest/Final-Mystic-Quest/Ferrum.ttf");
    
    // tous les entités ont un niveau initiale à 5 
    attributes[LEVEL]=5;
    for(int i = EXP; i < STATSCOUNT; i++)
    {
		attributes[i] = 0;
	}
	
	statusBits = 0;
	
	// pas de texte à afficher
	textTicks = 0;
	textColor = WHITE;
	
}

Entity::~Entity(){
	
}

void Entity::setAttribute(Stats s, int val) {
	
	if(s >= LEVEL && s <= STATSCOUNT)
	{
		attributes[val] = s;
	}		
	
}

bool Entity::hasStatus(unsigned int status) {
	
	return (statusBits & (1 << status));

}	

bool Entity::setStatus(unsigned int status) {
	
	// l'entité a déja une altération d'état
	if(hasStatus(status))
	{
		return 0 ;
	}
	
	// me en place le bit d'altération d'états
	statusBits |= 1 << status;
	return 1;	// succés de mise en place de l'altération d'état

}		
/*	
void Entity::resetTurn() {
	
	turn.action = NONE;
	
}*/ 

void Entity::setTarget(int target) {
	
	turn.target = target;
	
}

void Entity::setName(std::string n){
	name =n;
}

std::string Entity::getName(){
	return name;
}

void Entity::attack(int target) {
	
	turn.action = ATTACK;
	turn.target = target;
	
}
	
int Entity::getSpriteDim() { 
	
	return spriteDim; 

}
/*
void Entity::setTurn(Turn t) {
	
	turn = t;
}

Entity::Turn Entity::getTurn() const {
	
	return turn;

}*/
