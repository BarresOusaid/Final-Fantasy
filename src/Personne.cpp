#include "Personne.hpp"


Personne::Personne(){
	nom="";
	vie=0;
	niveau=0;
}

Personne::Personne(std::string nom, int vie,int niveau){
	this->nom=nom;
	this->vie=vie;
	this->niveau=niveau;
}

Personne::~Personne(){
	std::cout<<"Personne détruit";
}

bool Personne::isStatic(){
	return false;
}
/*
virtual Element* const clone(){
	return new Personne(*this);
}
*/
 bool Personne::isJoueur() const{
	return true; 	
 }
/*
 void Personne::attaquer(Personne p, Objet objet){
 	p.vie= p.vie-objet.puissance;
 }*/

 /*void Personne::utiliserObjet(Objet o){

 }*/

 int const Personne::getNiveau(){
 	return this->niveau;
 }

 int const Personne::getVie(){
 	return this->vie;
 }

 std::string const Personne::getNom(){
 	return this->nom;
 }

void Personne::setNiveau(int niveau){
	this->niveau = niveau;
}
void Personne::setVie(int vie){
	this->vie=vie;
}
void Personne::setNom(std::string nom){
	this->nom=nom;
}