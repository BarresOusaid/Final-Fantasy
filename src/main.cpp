//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Player.hpp"
#include "TileMap.hpp"
#include "Map.hpp"
#include "Input.hpp"
#include "CollisionManager.hpp"
#include <thread>

using namespace sf;
using namespace std;

Event event;

Player *player = new Player();
Player *second = new Player(1,1,"Hero");

Input *input = new Input();

Map *map_1 = new Map();

RenderWindow window(sf::VideoMode(1025, 800, 32), "SFML window", Style::Default);

/****************** Il s'agit du thread se chargeant d'une partie du moteur du jeu(mouvement du personnage principal) ***************/
/**********************************************************************************/
void character_movement(void)
{
    input->pollInput(event);
    if(CollisionManager::collidesWithMap(map_1))
    {
        player->moveCharacterSprite(input->getDirection());
    }
}
/**********************************************************************************/
/**********************************************************************************/

/****************** Il s'agit du thread se chargeant d'une partie du moteur du jeu(collision et IA) ***************/
/**********************************************************************************/
void collision_render(void)
{
    map_1->init(player, input);
    map_1->popMap(1, map_1);
    int xPos, yPos;
    xPos=player->getTileMap().getPosition().x;
    yPos=player->getTileMap().getPosition().y;
    
    if(CollisionManager::collidesWithPlayer(player, second)==1)
    {
        second->moveCharacterSprite_auto(1,2,2);
    }
    
    if(((!CollisionManager::collidesWithMap(map_1))))
    {
        player->moveCharacterSprite_auto(2, 1, 1);
    }
    second -> moveCharacterSprite_IA(map_1);
}
/**********************************************************************************/
/**********************************************************************************/


/****************** Il s'agit du thread se chargeant de l'affichage ***************/
/**********************************************************************************/
void render(void)
{
        
    // Clear screen
    window.clear();
        
    // Draw the sprite
    window.draw(map_1->getMap());
        
    // Draw the string
    window.draw(player->getTileMap());
    window.draw(second->getTileMap());
        
    // Update the window
    window.display();
}
/**********************************************************************************/
/**********************************************************************************/


int main(int, char const**)
{
        
    Time time;
    
    Clock clock;
    
    while (window.isOpen())
    {
        thread moteur_jeu_1(collision_render);
        moteur_jeu_1.join();
        
        // Process events
        while (window.pollEvent(event))
        {
            thread moteur_jeu_2(character_movement);
            moteur_jeu_2.join();
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }
        
        thread rendu(render);
        rendu.join();
        
    }
    return EXIT_SUCCESS;
}
