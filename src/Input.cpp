#include "Input.hpp"

Input::Input() {
	
	// configuration des contrôles du jeu
	confirm = &keys[68];	// 'd'
	cancel = &keys[83];		// 's'
	start = &enter;			// enter
	select = &keys[0];		// espace
	lButton = &keys[81];	// 'q'
	rButton = &keys[69];	// 'e'

	resetAllInput();
	
}

Input::~Input()
{
}

//Getter des touches
bool Input::getConfirm() 
{ 
	return *confirm; 
}
		
bool Input::getCancel() 
{ 
	return *cancel; 
}
		
bool Input::getStart() 
{ 
	return *start; 
}
		
bool Input::getSelect() 
{ 
	return *select; 		
}
		
bool Input::getLButton() 
{ 
	return *lButton; 
}
		
bool Input::getRButton() 
{ 
	return *rButton; 
}

// touches directionnelles
bool Input::upPressed()
{ 
	return up; 
}

bool Input::downPressed()
{ 
	return down; 
}

bool Input::leftPressed() 
{ 
	return left; 
}

bool Input::rightPressed() 
{ 
	return right; 
}

DIRECTION Input::getDirection(){
	return direction;
}

void Input::setDirection(DIRECTION direct){
	direction = direct;
}



//faire un retour de  direction 
/*bool Input::pollInput(sf::Event &event) {
	
	switch(event.type)
	{
		case sf::Event::KeyPressed:
			for (char ch = ' '; ch <= '~'; ch++) 
			{
				// i only care about character keys
				if (event.key.code == ch) {
					// the first 32 ASCII keys are junk
					keys[ch - 32] = 1;
				}
			}
		
			switch(event.key.code)
			{
				case sf::Keyboard::Tab:
				tab=1;
					break;
				
				case sf::Keyboard::BackSpace:
				backspace=1;
					break;
				
				case sf::Keyboard::Return:
				enter=1;
					break;
				
				case sf::Keyboard::Up:
				up=1;
					break;
				
				case sf::Keyboard::Down:
				down=1;
					break;
				
				case sf::Keyboard::Left:
				left=1;
					break;
				
				case sf::Keyboard::Right:
				right=1;
					break;
			}	 	
			break;
			
		case sf::Event::KeyReleased:
			for (char ch = ' '; ch <= '~'; ch++) 
			{
				// i only care about character keys
				if (event.key.code == ch) {
					// the first 32 ASCII keys are junk
					keys[ch - 32] = 0;
				}
			}
		
			switch(event.key.code)
			{
				case sf::Keyboard::Tab:
				tab=0;
					break;
				
				case sf::Keyboard::BackSpace:
				backspace=0;
					break;
				
				case sf::Keyboard::Return:
				enter=0;
					break;
				
				case sf::Keyboard::Up:
				up=0;
					break;
				
				case sf::Keyboard::Down:
				down=0;
					break;
				
				case sf::Keyboard::Left:
				left=0;
					break;
				
				case sf::Keyboard::Right:
				right=0;
					break;
			}	 	
			break;
	}
	return true;
}
*/
void Input::resetAllInput() {
	
	tab = 0;
	backspace = 0;
	enter = 0;

	up = 0;
	down = 0;
	left = 0;
	right = 0;

}

void Input::resetStart(){
	std::cout <<"makhdamch"<< std::endl;
}

bool Input::anyKey() {
	
	if (tab || backspace || enter || up || down || left || right) 
	{
		return true;
	}
	return false;
}			
		
DIRECTION Input::pollInput(sf::Event &event) {
	
	switch(event.type)
	{
		case sf::Event::KeyPressed:
			for (char ch = ' '; ch <= '~'; ch++) 
			{
				// i only care about character keys
				if (event.key.code == ch) {
					// the first 32 ASCII keys are junk
					keys[ch - 32] = 1;
				}
			}
		
			switch(event.key.code)
			{
				case sf::Keyboard::Tab:
				tab=1;
					break;
				
				case sf::Keyboard::BackSpace:
				backspace=1;
					break;
				
				case sf::Keyboard::Return:
				enter=1;
					break;
				
				case sf::Keyboard::Up:
				direction = HAUT;
				up=1;
					break;
				
				case sf::Keyboard::Down:
				direction = BAS;
				down=1;
					break;
				
				case sf::Keyboard::Left:
				direction = GAUCHE;
				left=1;
					break;
				
				case sf::Keyboard::Right:
				direction = DROITE;
				right=1;
					break;
			}	 	
			break;
			
		case sf::Event::KeyReleased:
			for (char ch = ' '; ch <= '~'; ch++) 
			{
				// i only care about character keys
				if (event.key.code == ch) {
					// the first 32 ASCII keys are junk
					keys[ch - 32] = 0;
				}
			}
		
			switch(event.key.code)
			{
				case sf::Keyboard::Tab:
				tab=0;
					break;
				
				case sf::Keyboard::BackSpace:
				backspace=0;
					break;
				
				case sf::Keyboard::Return:
				enter=0;
					break;
				
				case sf::Keyboard::Up:
				direction = NO;
				up=0;
					break;
				
				case sf::Keyboard::Down: 
				direction = NO;
				down=0;		
					break;
		
				case sf::Keyboard::Left:
				direction = NO;
				left=0;
					break;
				
				case sf::Keyboard::Right:
				direction = NO;
				right=0;
					break;
			}	 	
			break;
	}
	return NO;
}

					
