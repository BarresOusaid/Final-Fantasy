#ifndef Element_H
#define Element_H

#include <cstdlib>
#include <iostream>
#include "Direction.hpp"
#include "TypeId.hpp"


class Element{
 
 protected:
 		int x; 
 		int y;
 		Direction::Direction  orientation;

 public:
 		//constructeur et destructeur
 		Element();
 		~Element();

 		//getter des attributs
 		int const getX();
 		int const getY();
 		Direction::Direction const getOrientation();

 		//setter des attributs
 		void setX(int);
 		void setY(int);
 		void setOrientation(Direction::Direction);

 		//methodes utiles 

 		virtual TypeId::TypeId getTypedId()=0;
 		virtual bool isStatic()=0;
 		//virtual Element* const clone()=0;
 };
 #endif