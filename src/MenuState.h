#ifndef MENUSTATE__H
#define MENUSTATE__H

#include "Input.h"
#include "State.h"

/// class MenuState - 
class MenuState : public State {
  // Attributes
private:
  Map* head;
  Map* tail;
  // Operations
public:
  MenuState ();
  ~MenuState ();
  void pushMenu (menu* menu);
  void popMenu ();
  void changeMenu (Menu* menu);
  int getSize ();
  void setInput (Input i);
  void exitMenus (bool startGame = 0);
};

#endif
