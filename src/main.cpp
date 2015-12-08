
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



// Here is a small helper for you ! Have a look.
using namespace sf;
using namespace std;



int main(int, char const**)
{
    
    RenderWindow window(sf::VideoMode(1025, 800, 32), "SFML window", Style::Default);
    Time time;
    Clock clock;
    Player *player = new Player();
    Player *second = new Player(2,2,"Hero");
    //MapState *mapstate = new MapState();
    Input *input = new Input();
    /*Enemy enemy;
    enemy.init("Battle");*/

    Map *map = new Map();
    /*View view(sf::FloatRect(0, 0, 1000, 800));
    window.setView(view);*/
    while (window.isOpen())
    {	
        //map->init(player, input);
        map->init(player, input);
        map->popMap(1, map);

        sf::Event event;
        
        player -> moveCharacterSprite_IA(map);
        
        while (window.pollEvent(event))
        {
            input->pollInput(event);
            
            //second->moveCharacterSprite(input);
            player -> moveCharacterSprite(input -> getDirection());
           // player -> moveCharacterSprite_IA(map);
            
            if(CollisionManager::collidesWithPlayer(player, second)==1)
            {
                second->moveCharacterSprite_auto(3);
            }
                        
            if(event.type == Event::Closed)
            {
                window.close();
            }	
        }
        
        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(map->getMap());
        
        // Draw the string
        window.draw(player->getTileMap());
        window.draw(second->getTileMap());

        
        // Update the window
        window.display();
        
    }
    
    return EXIT_SUCCESS;
}
