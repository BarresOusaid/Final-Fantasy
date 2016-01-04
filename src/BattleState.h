#ifndef BATTLESTATE__H
#define BATTLESTATE__H

#include "State.h"
#include "enum.h"

/// class BattleState - 
class BattleState : public State {
  // Associations
  // Attributes
public:
  ENEMY enemy[ENEMYSLOTS];
private:
  int battleID;
  bool preemptive;
  bool surprise;
  int currentSlot;
  bool enemyLocs[EnemySlots];
  bool executingTurns;
  int attackSequence[SLOTCOUNT];
  MenuState* menuState;
  BattleBGMenu* battleBGMenu;
  Textures textures;
  // Operations
public:
  BattleState (int battleID, int advantage);
  ~BattleState ();
private:
  void update ();
  void render ();
  void enemyDecide ();
  void enemyAct ();
  void characterDecide ();
  void characterAct ();
  void battleOver ();
  void pause ();
  void unpause ();
};

#endif
