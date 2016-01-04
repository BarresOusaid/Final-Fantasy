#ifndef TURN__H
#define TURN__H

#include "Actions.h"

struct Turn {
  Actions action;
  int target;
  int actionID;
};

#endif
