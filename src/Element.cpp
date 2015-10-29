#include "Element.hpp"


Element::Element(){
	x=0;
	y=0;
	orientation=Direction::NONE;
}

Element::~Element(){
	std::cout <<"Element detruit";
}

//getter des attributs
 	int const Element::getX(){
 		return x;
 	}

 	int const Element::getY(){
 		return y;
 	}

 	Direction::Direction const Element::getOrientation(){
 		return orientation;
 	}

 //setter des attributs
 	void Element::setX(int x){
 		this->x=x;
 	}
 	void Element::setY(int y){
 		this->y=y;
 	}
 	void Element::setOrientation(Direction::Direction orientation){
 		this->orientation = orientation;
 	}