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
 		DIRECTION::DIRECTION  orientation;

 public:
 		//constructeur et destructeur
 		Element();
 		~Element();

 		//getter des attributs
 		int const getX();
 		int const getY();
 		DIRECTION::DIRECTION const getOrientation();

 		//setter des attributs
 		void setX(int);
 		void setY(int);
 		void setOrientation(DIRECTION::DIRECTION);

 		//methodes utiles 

 		virtual TypeId::TypeId getTypedId()=0;
 		virtual bool isStatic()=0;
 		virtual Element* clone() const =0;
 };
 #endif