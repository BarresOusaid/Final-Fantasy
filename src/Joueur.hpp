#ifndef JOUEUR_H
#define JOUEUR_H

#include <cstdlib>
#include <iostream>
#include <string> 
#include "Butin.hpp"
#include "Personne.hpp"

class Joueur : public Personne {

	protected: 
			int experience;
			Butin* butin;

	public:
			//constructeur	
			Joueur();
			Joueur(int, Butin*);
			//destructeur
			~Joueur();

			//getter setter de la classe joueur

			int const getExperience();
			Butin* const getButin();

			Element* clone() const;

			TypeId::TypeId getTypedId();

			void setExperience(int);
			void setButin(Butin*);

			//Methode pour la classe Joueur

			bool const isJoueur();
};




#endif
