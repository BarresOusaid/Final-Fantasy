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
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "Player.hpp"
#include "TileMap.hpp"
#include "Map.hpp"
#include "Input.hpp"
#include "CollisionManager.hpp"
#include <thread>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

Event event;

Player *player = new Player();
Player *second = new Player(2,2,"Hero");

Input *input = new Input();

Map *map_1 = new Map();

RenderWindow window(sf::VideoMode(1025, 800, 32), "SFML window", Style::Default);

int test=0;

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
    /*sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    char connectionType;
    
    cout << "(s) for server, (c) for client: ";
    cin >> connectionType;
    
    if(connectionType=='s')
    {
        sf::TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
    }
    else
    {
        socket.connect(ip,2000);
    }
    Time time;
    
    Clock clock;
    
    socket.setBlocking(false);
    
    while (window.isOpen())
    {
     if(connectionType=='s')
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
     }
     else
     {
        thread rendu(render);
        rendu.join();
     }
    }
    return EXIT_SUCCESS;*/
    IpAddress ip = sf::IpAddress::getLocalAddress();
    TcpSocket socket;
    char connectionType;
     
    cout << "(s) for server, (c) for client: ";
    cin >> connectionType;
     
    if(connectionType=='s')
     {
         sf::TcpListener listener;
         listener.listen(2000);
         listener.accept(socket);
     }
     else
     {
         socket.connect(ip,2000);
     }
    
    RectangleShape rect1, rect2;
    rect1.setSize(Vector2f(20, 20));
    rect2.setSize(Vector2f(20, 20));
    
    rect1.setFillColor(Color::Red);
    rect2.setFillColor(Color::Blue);
    
    sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Testing");
    sf::Vector2f prevPosition, p2Positon;
    
    socket.setBlocking(false);
    
    bool update=false;
    
    while(Window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed || event.key.code == Keyboard::Escape)
            {
                Window.close();
            }
            else if(event.type == Event::GainedFocus)
            {
                update = true;
            }
            else if (event.type == Event::LostFocus)
            {
                update = false;
            }
            
            prevPosition=rect1.getPosition();
        }
        if(update)
        {
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                rect1.move(1.0f, 0.0f);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                rect1.move(-1.0f, 0.0f);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                rect1.move(0.0f, -1.0f);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                rect1.move(0.0, 1.0f);
            }
        }
        Packet packet;
        if(prevPosition !=rect1.getPosition())
        {
            packet << rect1.getPosition().x << rect1.getPosition().y;
            socket.send(packet);
        }
        
        socket.receive(packet);
        if(packet >> p2Positon.x >> p2Positon.y)
        {
            rect2.setPosition(p2Positon);
        }
        Window.draw(rect1);
        Window.draw(rect2);
                
        Window.display();
        Window.clear();
    }

}
