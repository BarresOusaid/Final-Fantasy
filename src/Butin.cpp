
#include "Butin.hpp"

				Butin::Butin(){
					 std::vector<Objet> contenu;
				}

				Butin::~Butin(){
					std::cout <<"Butin détruit";	
				}

				//methode de la classe Butin


		/*	void Butin::presentation(const std::vector<Objet> & contenu, std::string nom)
			{
			    for(int i = 0;i < contenu.size();i++)
			    {
			        if(contenu[i].getNom() == nom)
			        {
			            contenu.erase(i);
			            break;
			        }
			    }
/*

				void Butin::ajouterObjet(std::string nom){
					contenu.push_back(nom);
				}
				
				void Butin::supprimerObjet (std::string nom){
				
				   for (size_t i = 0; i < contenu.size(); i++) 
   					 { 
    					if (contenu[i].getNom() == nom)
    					     {
    					     	contenu.erase(i);
    					     }     
   					 } 
				}*/

				std::vector<Objet> const Butin::getContenu(){
						return contenu;
				}