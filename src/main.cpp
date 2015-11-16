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
    int direction = 0;
    RenderWindow window(sf::VideoMode(1000, 800, 32), "SFML window", Style::Default);
    Time time;
    Clock clock;

    // create the tilemap from the level definition
    TileMap map;
    map.setPosition(200, 200);
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
    if (!texture.loadFromFile("../res/Village/Mystic_Quest_village_1.png"))
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
    Font font;
    if (!font.loadFromFile("../res/Songs/Ferrum.ttf"))
    {
        return EXIT_FAILURE;
    }
    Text text("Final Mystic Quest", font, 50);
    text.setColor(Color::Black);

    // Load a music to play
    Music music;
    if (!music.openFromFile("../res/Songs/City_of_wind.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    //music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(direction == 0)
            {
                level[0] = 1;
                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                    return -1;
            }
            
            if(direction == 1)
            {
                level[0] = 1;
                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                    return -1;
            }
            
            if(direction == 2)
            {
                level[0] = 10;
                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                    return -1;
            }
            
            if(direction == 3)
            {
                level[0] = 4;
                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                    return -1;
            }
            
            if(direction == 4)
            {
                level[0] = 7;
                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                    return -1;
            }
            
         
            // Close window: exit
            switch (event.type)
            {
                case Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Down:
                            i_down++;
                            direction = 1;
                            if(i_down % 2 == 0)
                            {
                                level[0] = 0;
                                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                                    return -1;
                                map.move(0, 3);
                            }
                            if(i_down % 2 == 1)
                            {
                                level[0] = 2;
                                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                                    return -1;
                                map.move(0, 3);
                                
                            }
                            break;
                            
                        case sf::Keyboard::Up:
                            i_up++;
                            direction = 2;
                            if(i_up % 2 == 0)
                            {
                                level[0] = 9;
                                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                                    return -1;
                                map.move(0, -3);
                            }
                            if(i_up % 2 == 1)
                            {
                                level[0] = 11;
                                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                                    return -1;
                                map.move(0, -3);
                            }
                            break;

                            
                        case sf::Keyboard::Left:
                            i_left++;
                            direction = 3;
                            if(i_left % 2 == 0)
                            {
                                level[0] = 3;
                                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                                    return -1;
                                map.move(-3, 0);
                            }
                            if(i_left % 2 == 1)
                            {
                                level[0] = 5;
                                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                                    return -1;
                                map.move(-3, 0);
                            }
                            break;
                            
                        case sf::Keyboard::Right:
                            i_right++;
                            direction = 4;
                            if(i_right % 2 == 0)
                            {
                                level[0] = 6;
                                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                                    return -1;
                                map.move(3, 0);
                            }
                            if(i_right % 2 == 1)
                            {
                                level[0] = 8;
                                if (!map.load("../res/Characters/Benjamin.png", sf::Vector2u(32, 32), level, 1, 1))
                                    return -1;
                                map.move(3, 0);
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
        window.draw(map);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
