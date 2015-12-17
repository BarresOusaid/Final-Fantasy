#ifndef STATE__H
#define STATE__H

#include "Input.h"

/// class State - 
class State {
  // Attributes
protected:
  Input input;
  Player* player;
  State* next;
  State* prev;
  int windowWidth;
  int windowHeight;
  // Operations
public:
  State ();
  ~State ();
private:
  void processState (sf::Event &event);
protected:
  void init (Player* p);
  State* getNextState ();
  State* getPreviousState ();
  void setNextState (State* state);
  void setPreviousState (State* state);
};

#endif
