#include "Graphique.hpp"


 			Graphique::Graphique(){

 				nom = "";
 			}
 			Graphique::Graphique(std::string nom){

 				this -> nom = nom;
 			}
 			//destructeur
 			Graphique::~Graphique(){

 				std::cout<<"Graphique detruit";
 			}

 			bool Graphique::equals(const Element *e){

 				if(this == e){
 					return true;
 				}
 				else {return false;}
 			}

 			 