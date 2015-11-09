#ifndef OBJET_H
#define OBJET_H

#include <cstdlib>
#include <iostream>
#include <string> 
#include "ObjetTypeId.hpp"
#include "Graphique.hpp"
#include "TypeId.hpp"

class Objet : public Graphique{

	protected:

		std::string nom;
		int valeur;
		ObjetTypeId::ObjetTypeId typeObjet;

	public:

		//constructeur de la classe objet
		Objet();
		Objet(std::string, int , ObjetTypeId::ObjetTypeId);

		//destructeur d'objet
		~Objet();

		//methode de la classe 
		std::string const getNom();
		TypeId::TypeId getTypedId();
		bool isStatic();
		bool franchir();
		Element* clone() const;


};

#endif