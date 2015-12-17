#ifndef INPUT__H
#define INPUT__H

#include "DIRECTION.h"

/// class Input - 
class Input {
  // Attributes
private:
  bool * confirm;
  bool* cancel;
  bool* start;
  bool* select;
  bool* lButton;
  bool* rButton;
  bool up;
  bool down;
  bool left;
  bool right;
  bool backspace;
  bool enter;
  bool tab;
  DIRECTION direction;
  bool keys[96];
  // Operations
public:
  Input ();
  ~Input ();
  void resetAllInput ();
  bool getConfirm ();
  bool getCancel ();
  bool getStart ();
  bool getSelect ();
  bool getLButton ();
  bool getRButton ();
  void resetConfirm ();
  void resetCancel ();
  void resetStart ();
  void resetSelect ();
  void resetLButton ();
  void resetRButton ();
  bool upPressed ();
  bool downPressed ();
  bool leftPressed ();
  bool rightPressed ();
  DIRECTION getDirection ();
  void setDirection (DIRECTION direct);
  bool anyKey ();
  DIRECTION pollInput (sf::Event& event);
};

#endif
