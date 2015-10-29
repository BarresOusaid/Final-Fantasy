#ifndef Graphique_H
#define Graphique_H

#include <cstdlib>
#include <iostream>
#include <string> 
#include "Element.hpp"



class Graphique : public Element{
 
 protected:
 			std::string nom;

 public:
 			//Constructeur 
 			Graphique();
 			Graphique(std::string);
 			//destructeur
 			~Graphique();

 			//méthode 
 			virtual bool franchir()=0;
 			bool equals(const Element *e);

 };
 
  #endif