#ifndef INPUT_H
#define INPUT_H

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>

class Input {
	
public :
	Input();
	~Input();
	bool pollInput(sf::Event &event);
	
	void resetAllInput();
	
	//getter des touches
	bool getConfirm();
	bool getCancel();
	bool getStart(); 
	bool getSelect();
	bool getLButton(); 
	bool getRButton();
	
	// reset individuel
	void resetConfirm();
	void resetCancel(); 
	void resetStart();
	void resetSelect(); 
	void resetLButton(); 
	void resetRButton();
	
	// touches diectionnelles
	bool upPressed(); 
	bool downPressed(); 
	bool leftPressed(); 
	bool rightPressed();
	
	// vérifie si une touche à été appuyée
	bool anyKey(); 
	
private:
	// configuration des contrôles du jeu
	bool *confirm, *cancel, *start, *select, *lButton, *rButton;

	bool keys[96];				// character keys
	bool up, down, left, right; // arrow keys
	bool tab, backspace, enter; // tab, backspace, enter keys
	
};	

#endif
