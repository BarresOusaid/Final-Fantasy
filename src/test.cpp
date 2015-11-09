#include "Factory.hpp"
#include "Joueur.hpp"
#include "Objet.hpp"
#include "Element.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
  //notre fabrique
  Factory <Element> fac;

 //on enregistre des types
  Factory<Element>::Register("Joueur",new Joueur);

  //on crée des objets via la fabrique
  
  std::unique_ptr<Element> c ( fac.Create("Joueur"));

  c->setX(12);

  std::cout << c -> getX();

  return 0;
}