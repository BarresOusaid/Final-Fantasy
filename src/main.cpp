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


// Here is a small helper for you ! Have a look.


using namespace sf;
using namespace std;


int main(int, char const**)
{
    /////////////// Movement key identifier ///////////////
    int i_down = 0;
    int i_up = 0;
    int i_left = 0;
    int i_right = 0;
    int directionID = 0;
    RenderWindow window(sf::VideoMode(1000, 800, 32), "SFML window", Style::Default);
    Time time;
    Clock clock;
    Player player;
    player.getTileMap().setPosition(200, 200);
    // create the tilemap from the level definition
    int level[] = {0};
    View view(sf::FloatRect(0, 0, 500, 500));
    
    window.setView(view);
    window.setFramerateLimit(60);
    
    /////////////// Load a Sprite ///////////////
    Sprite sprite;
    /////////////////////////////////////////////
    
    /////////////// Load a texture ///////////////
    Texture texture;
    /////////////// Loading Village image ///////////////
    if (!texture.loadFromFile("../Sprites/Village/Mystic_Quest_village_1.png"))
    {
        return EXIT_FAILURE;
    }
    /////////////// Setting Smootness for texture ///////////////
    texture.setSmooth(true);
    /////////////////////////////////////////////////////////////
    
    /////////////// Assigning Spirite to texture ///////////////
    sprite.setTexture(texture);
    ////////////////////////////////////////////////////////////
    
    /////////////// Setting Sprite color ///////////////
    sprite.setColor(Color(0, 100, 255));
    ////////////////////////////////////////////////////
    
    /////////////// Scaling Sprite ///////////////
    sprite.setScale((Vector2f(1, 1)));
    /////////////// Create a graphical text to display ///////////////
    /*Font font;
    if (!font.loadFromFile("../res/Songs/Ferrum.ttf"))
    {
        return EXIT_FAILURE;
    }*/
    /*Text text("Final Mystic Quest", font, 50);
    text.setColor(Color::Black);*/
    
    // Load a music to play
    /*Music music;
    if (!music.openFromFile("../res/Songs/City_of_wind.ogg")) {
        return EXIT_FAILURE;
    }*/
    
    // Play the music
    //music.play();
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (directionID)
            {
                case 1:
                player.changeCharacterSpriteDirection(1);
                    break;
                    
                case 2:
                player.changeCharacterSpriteDirection(10);
                    break;
            
                case 3:
                player.changeCharacterSpriteDirection(4);
                    break;
                    
                case 4:
                player.changeCharacterSpriteDirection(7);
                    break;
        
                default:
                player.changeCharacterSpriteDirection(1);
                    break;
            }
            
            // Close window: exit
            switch (event.type)
            {
                case Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Down:
                            i_down++;
                            directionID = 1;
                            if(i_down%2 == 0)
                            {
                                player.changeCharacterSpriteDirection(0);
                                player.moveCharacterSprite(Player::SOUTH);
                            }
                            if(i_down%2 == 1)
                            {
                                player.changeCharacterSpriteDirection(2);
                                player.moveCharacterSprite(Player::SOUTH);
                            }
                                break;
                        
                        case sf::Keyboard::Up:
                            i_up++;
                            directionID = 2;
                            if(i_up % 2 == 0)
                            {
                                player.changeCharacterSpriteDirection(9);
                                player.moveCharacterSprite(Player::NORTH);
                            }
                            if(i_up % 2 == 1)
                            {
                                player.changeCharacterSpriteDirection(11);
                                player.moveCharacterSprite(Player::NORTH);
                            }
                                break;
                        
                        case sf::Keyboard::Left:
                            i_left++;
                            directionID = 3;
                            if(i_left % 2 == 0)
                            {
                                player.changeCharacterSpriteDirection(3);
                                player.moveCharacterSprite(Player::WEST);
                            }
                            if(i_left % 2 == 1)
                            {
                                player.changeCharacterSpriteDirection(5);
                                player.moveCharacterSprite(Player::WEST);
                            }
                                break;
                        
                        case sf::Keyboard::Right:
                            i_right++;
                            directionID = 4;
                            if(i_right % 2 == 0)
                            {
                                player.changeCharacterSpriteDirection(6);
                                player.moveCharacterSprite(Player::EAST);
                            }
                            if(i_right % 2 == 1)
                            {
                                player.changeCharacterSpriteDirection(8);
                                player.moveCharacterSprite(Player::EAST);
                            }
                                break;
                    }
                        break;
                    
                case Event::Closed:
                    window.close();
                        break;
                    
            }
        }
        
        
        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(sprite);
        
        // Draw the string
        window.draw(player.getTileMap());
        
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}