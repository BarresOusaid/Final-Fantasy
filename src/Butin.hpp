#ifndef Butin_H
#define Butin_H

#include "Objet.hpp"
#include <cstdlib>
#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm>


class Butin{
		private:
				std::vector<Objet> contenu;

		public:
				Butin();
				~Butin();

				//methode de la classe Butin
				//void presentation(const std::vector<Objet> & contenu, std::string nom);
				//void ajouterObjet(std::string);
				//void supprimerObjet(std::string);
				std::vector<Objet> const getContenu();
};

#endif