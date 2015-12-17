#ifndef TITLESTATE__H
#define TITLESTATE__H

#include "State.h"
#include "TewInfo.h"
#include "Options.h"

/// class TitleState - 
class TitleState : public State {
  // Associations
  // Attributes
private:
  Font twenty;
  Font sixteen;
  Cursor cursor;
  // Operations
public:
  TitleState ();
  ~TitleState ();
};

#endif
