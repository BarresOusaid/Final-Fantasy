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

using namespace sf;
using namespace std;

/////////////// Movement key identifier ///////////////
int i_down = 0;
int i_up = 0;
int i_left = 0;
int i_right = 0;
///////////////////////////////////////////////////////
int main(int, char const**)
{
    
    int j = 0;
    /////////////// Create the main window ///////////////
    RenderWindow window(sf::VideoMode(1000, 800, 32), "SFML window", Style::Default);
    //////////////////////////////////////////////////////
    
    Time time;
    Clock clock;
    
    View view(sf::FloatRect(0, 0, 500, 500));
    window.setView(view);
    
    /////////////// Set the Icon ///////////////
    Image icon;
    if (!icon.loadFromFile( "../res/Objects/icon.png"))
    {
        return EXIT_FAILURE;
    }
    ////////////////////////////////////////////
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);
    
    /////////////// Load a Sprite ///////////////
    Sprite sprite;
    Sprite hero_down[3];
    Sprite hero_up[3];
    Sprite hero_left[3];
    Sprite hero_right[3];
    /////////////////////////////////////////////
    
    /////////////// Load a texture ///////////////
    Texture texture;
    Texture hero_down_text[3];
    Texture hero_up_text[3];
    Texture hero_left_text[3];
    Texture hero_right_text[3];
    //////////////////////////////////////////////

   
    /////////////// Loading Village image ///////////////
    if (!texture.loadFromFile("../res/Village/village.png"))
    {
        return EXIT_FAILURE;
    }
    /////////////////////////////////////////////////////
    
    /////////////// Loading character down ///////////////
    if (!hero_down_text[0].loadFromFile("../res/Characters/Benjamin_Down_1.png"))
    {
        return EXIT_FAILURE;
    }
    
    if (!hero_down_text[1].loadFromFile("../res/Characters/Benjamin_Down_2.png"))
    {
        return EXIT_FAILURE;
    }
    
    if(!hero_down_text[2].loadFromFile("../res/Characters/Benjamin_Down_3.png"))
    {
        return EXIT_FAILURE;
    }
    /////////////////////////////////////////////////////
    
    /////////////// Loading character up ////////////////
    if (!hero_up_text[0].loadFromFile("../res/Characters/Benjamin_Up_1.png"))
    {
        return EXIT_FAILURE;
    }
    
    if (!hero_up_text[1].loadFromFile("../res/Characters/Benjamin_Up_2.png"))
    {
        return EXIT_FAILURE;
    }
    
    if(!hero_up_text[2].loadFromFile("../res/Characters/Benjamin_Up_3.png"))
    {
        return EXIT_FAILURE;
    }
    ////////////////////////////////////////////////////
    
    /////////////// Loading character left ////////////////
    if (!hero_left_text[0].loadFromFile("../res/Characters/Benjamin_Left_1.png"))
    {
        return EXIT_FAILURE;
    }
    
    if (!hero_left_text[1].loadFromFile("../res/Characters/Benjamin_Left_2.png"))
    {
        return EXIT_FAILURE;
    }
    
    if(!hero_left_text[2].loadFromFile("../res/Characters/Benjamin_Left_3.png"))
    {
        return EXIT_FAILURE;
    }
    ///////////////////////////////////////////////////////

    /////////////// Loading character right ////////////////
    if (!hero_right_text[0].loadFromFile("../res/Characters/Benjamin_Right_1.png"))
    {
        return EXIT_FAILURE;
    }
    
    if (!hero_right_text[1].loadFromFile("../res/Characters/Benjamin_Right_2.png"))
    {
        return EXIT_FAILURE;
    }
    
    if(!hero_right_text[2].loadFromFile("../res/Characters/Benjamin_Right_3.png"))
    {
        return EXIT_FAILURE;
    }
    ////////////////////////////////////////////////////////
    

    /////////////// Setting Smootness for texture ///////////////
    texture.setSmooth(true);
    for(j=0; j<=3;j++)
    {
        hero_down_text[j].setSmooth(true);
        hero_up_text[j].setSmooth(true);
        hero_left_text[j].setSmooth(true);
        hero_right_text[j].setSmooth(true);
    }
    /////////////////////////////////////////////////////////////
    
    /////////////// Assigning Spirite to texture ///////////////
    sprite.setTexture(texture);
    for(j=0; j<=3;j++)
    {
        hero_down[j].setTexture(hero_down_text[j]);
        hero_up[j].setTexture(hero_up_text[j]);
        hero_left[j].setTexture(hero_left_text[j]);
        hero_right[j].setTexture(hero_right_text[j]);
    }
    ////////////////////////////////////////////////////////////
    
    /////////////// Setting Sprite color ///////////////
    sprite.setColor(Color(0, 100, 255));
    ////////////////////////////////////////////////////

    /////////////// Scaling Sprite ///////////////
    sprite.setScale((Vector2f(1, 1)));
    for(j=0; j<=3;j++)
    {
        hero_down[j].setScale(Vector2f(0.8, 0.8));
        hero_up[j].setScale(Vector2f(0.8, 0.8));
        hero_left[j].setScale(Vector2f(0.8, 0.8));
        hero_right[j].setScale(Vector2f(0.8, 0.8));
    }
    ////////////////////////////////////////////////////
    
    /////////////// Setting Sprite position ///////////////
    for(j=0; j<=3;j++)
    {
        hero_down[j].setPosition(Vector2f(200, 200));
        hero_up[j].setPosition(Vector2f(200, 200));
        hero_left[j].setPosition(Vector2f(200, 200));
        hero_right[j].setPosition(Vector2f(200, 200));
    }
    ////////////////////////////////////////////////////
    
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
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            switch (event.type)
            {
                case Event::Closed:
                    window.close();
                    break;
                    
                case Event::KeyPressed:
                    cout << "Key has been pressed" << endl;
                    
                    switch (event.key.code)
                    {
                
                        case Keyboard::Down:
                            i_down++;
                            if ( (hero_down[0].getGlobalBounds().height < 800) || (hero_down[1].getGlobalBounds().height < 800) || (hero_down[2].getGlobalBounds().height < 800) || (hero_down[3].getGlobalBounds().height < 800))
                            {
                                for(j=0; j<=2; j++)
                                {
                                    hero_down[j].move(Vector2f(0,5));
                                    hero_up[j].move(Vector2f(0,5));
                                    hero_left[j].move(Vector2f(0,5));
                                    hero_right[j].move(Vector2f(0,5));
                                }
                            }
                            break;
                            
                        case sf::Keyboard::Up:
                            i_up++;
                            for(j=0; j<=2; j++)
                            {
                                hero_up[j].move(Vector2f(0,-5));
                                hero_down[j].move(Vector2f(0,-5));
                                hero_left[j].move(Vector2f(0,-5));
                                hero_right[j].move(Vector2f(0,-5));
                            }
                            break;
                            
                        case sf::Keyboard::Left:
                            i_left++;
                            for(j=0; j<=2; j++)
                            {
                                hero_left[j].move(Vector2f(-5,0));
                                hero_up[j].move(Vector2f(-5,0));
                                hero_down[j].move(Vector2f(-5,0));
                                hero_right[j].move(Vector2f(-5,0));
                            }
                            break;
                            
                        case sf::Keyboard::Right:
                            i_right++;
                            for(j=0; j<=2; j++)
                            {
                                hero_right[j].move(Vector2f(5,0));
                                hero_left[j].move(Vector2f(5,0));
                                hero_up[j].move(Vector2f(5,0));
                                hero_down[j].move(Vector2f(5,0));
                            }
                            break;
                            
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                    }
                    break;
                    
                case sf::Event::Resized:
                    cout << event.size.width << endl;
                    break;
                    
                case sf::Event::LostFocus:
                    cout << "We have lost focus" << endl;
                    break;
                 
                case sf::Event::GainedFocus:
                    cout << "We have gained focus" << endl;
                    break;
                    
                case sf::Event::MouseMoved:
                    cout << "Position x :" << event.mouseMove.x << endl;
                    cout << "Position y :" << event.mouseMove.y << endl;
                    break;
                    
                case sf::Event::TextEntered:
                    cout << "Text has been entered" << endl;
                    
                    if( event.text.unicode == 66)
                    {
                        cout << "Capital B has been pressed" << endl;
                    }
                    break;
            }
        }
        
        /*if(sprite.getGlobalBounds().intersects(hero.getGlobalBounds()))
        {
            cout << "The sprite has collided" << endl;
        }
        else
        {
            hero.move(sf::Vector2f(0, -0.5));
            sprite.move(sf::Vector2f(0, +0.5));
        }*/
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            cout << "The left button has been pushed so what !!!!!!!" << endl;
        }
        
        cout << "Mouse position x is:" << Mouse::getPosition(window).x << endl;
        cout << "Mouse position y is:" << Mouse::getPosition(window).y << endl;
        
        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);
        switch (event.key.code)
        {
            case Keyboard::Down:
                if (i_down % 2 == 0)
                {
                    window.draw(hero_down[0]);
                }
        
                if (i_down % 2 == 1)
                {
                    window.draw(hero_down[2]);
                }
                break;
                
            case Keyboard::Up:
                if (i_up % 2 == 0)
                {
                    window.draw(hero_up[0]);
                }
                
                if (i_up % 2 == 1)
                {
                    window.draw(hero_up[2]);
                }
                break;
                
            case Keyboard::Left:
                if (i_left % 2 == 0)
                {
                    window.draw(hero_left[0]);
                }
                
                if (i_left % 2 == 1)
                {
                    window.draw(hero_left[2]);
                }
                break;
                
            case Keyboard::Right:
                if (i_right % 2 == 0)
                {
                    window.draw(hero_right[0]);
                }
                
                if (i_right % 2 == 1)
                {
                    window.draw(hero_right[2]);
                }
                break;
        }
       
        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
