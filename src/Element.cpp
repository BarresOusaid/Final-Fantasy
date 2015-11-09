#include "Element.hpp"


Element::Element(){
	x=0;
	y=0;
	orientation=DIRECTION::NONE;
}

Element::~Element(){
	std::cout <<"Element detruit"<< std::endl;
}

//getter des attributs
 	int const Element::getX(){
 		return x;
 	}

 	int const Element::getY(){
 		return y;
 	}

 	DIRECTION::DIRECTION const Element::getOrientation(){
 		return orientation;
 	}

 //setter des attributs
 	void Element::setX(int x){
 		this->x=x;
 	}
 	void Element::setY(int y){
 		this->y=y;
 	}
 	void Element::setOrientation(DIRECTION::DIRECTION orientation){
 		this->orientation = orientation;
 	}