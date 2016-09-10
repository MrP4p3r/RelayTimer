/*
 * Описание определений из "state.h"
 */

#include "state.h"

State* State::execute()
{
  this->setup();
  return this->loop();
}
