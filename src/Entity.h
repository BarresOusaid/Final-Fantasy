#ifndef ENTITY__H
#define ENTITY__H

#include "Turn.h"
#include "Stats.h"
#include "DIRECTION.h"
#include "Status.h"
#include "textColors.h"
#include "Actions.h"

/// class Entity - 
class Entity {
  // Associations
  // Attributes
private:
  std::string name;
  sf::Font twenty;
  Turn turn;
  unsigned int textTicks;
  int textColor;
  int change;
protected:
  int attributes[];
  int statusBits;
  unsigned int animateTicks;
  int renderX;
  int renderY;
  int spriteDim;
  // Operations
public:
  Entity ();
  ~Entity ();
  void setAttribute (Stats s, int val);
  bool hasStatus (unsigned int status);
  bool setStatus (unsigned int status);
  bool removeStatus (unsigned int status);
  int addHP (int amount);
  int addMP (int amount);
  void renderHPMPChange ();
  bool renderingHPMPChange ();
  void setName (std::string n);
  std::string  getName ();
  int getSpriteDim ();
  void setTarget (int target);
  void attack (int target);
};

#endif
