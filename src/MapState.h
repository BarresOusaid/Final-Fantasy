#ifndef MAPSTATE__H
#define MAPSTATE__H

#include "State.h"

/// class MapState - 
class MapState : public State {
  // Attributes
private:
  Map* head;
  Map* tail;
  // Operations
public:
  MapState ();
  ~MapState ();
  void pushMap (Map* map);
  void popMap ();
  void chageMap (Map* map);
  MenuState* enterMenu ();
  BattleState* Enterbattle (int battleID);
};

#endif
