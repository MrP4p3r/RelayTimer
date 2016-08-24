/*
 * Описание определений из "statectl.h"
 */

#include "statectl.h"
#include "state.h"

void StateController::loop(State* state)
{
  // Пока укзатель на state ненулевой
  Serial.println("state controller");
  for(;state;) state = state->execute();
}

