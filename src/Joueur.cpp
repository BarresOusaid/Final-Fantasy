# include "Joueur.hpp"


			Joueur::Joueur(){
					experience = 0;
					butin = NULL;
				}
			
			Joueur::Joueur(int experience, Butin* butin){
				this -> experience = experience;
				this -> butin = butin;
			}
			//destructeur
			Joueur::~Joueur(){
				std::cout <<"Joueur detruit";				
			}

			//getter setter de la classe joueur

			int const Joueur::getExperience(){
					return this -> experience;
			}

			Butin* const Joueur::getButin(){
					return this -> butin;
			}

			TypeId::TypeId Joueur::getTypedId(){
				return TypeId::joueur;
			}

			void Joueur::setExperience(int experience){

					this -> experience = experience;
			}

			void Joueur::setButin(Butin* butin){
					this -> butin = butin;
 			}

 			Element* Joueur::clone() const{
 				return new Joueur(*this);
 			}

			//Methode pour la classe Joueur

			bool const Joueur::isJoueur(){

					return true;
			}
