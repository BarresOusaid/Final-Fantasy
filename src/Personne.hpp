#ifndef Personne_H
#define Personne_H

#include <cstdlib>
#include <iostream>
#include <string> 
#include "Element.hpp"
#include "TypeId.hpp"


class Personne : public Element{
 
 protected:
 	std::string nom;
 	int niveau;
 	int vie;

 public:
 	//constructeur
 	Personne();
 	Personne(std::string,int,int);
 	//destructeur
 	~Personne();

 	//refefinition des methodes de la classe mere Element
 		bool isStatic();
 		//virtual Element* const clone();

 	//Définition des methodes propres a la classe joueur

 		bool isJoueur() const;
 		//void attaquer(Personne, Objet);
 		//void utiliserObjet(Objet);

 	// Definition des getter
 		int const getNiveau();
 		int const getVie();
 		std::string const getNom();

 	//definition des setter
 		void setNiveau(int);
 		void setVie(int);
 		void setNom(std::string);
 };
  #endif