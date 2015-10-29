#include "Objet.hpp"


		//constructeur de la classe objet
		Objet::Objet(){

		nom = "";
		valeur = 0;
		typeObjet = ObjetTypeId::walou;
		}

		Objet::Objet(std::string nom, int valeur , ObjetTypeId::ObjetTypeId typeObjet){
		
		this -> nom = nom;
		this -> valeur = valeur;
		this -> typeObjet = typeObjet;
		}

		//destructeur d'objet
		Objet::~Objet(){
			std::cout <<"objet DETRUIT";
		}

		std::string const Objet::getNom(){
			return nom;
		}

		TypeId::TypeId Objet::getTypedId(){
			return TypeId::objet;
		}

		bool Objet::isStatic(){
			return true;
		}

		bool Objet::franchir(){
			return false;
		}

