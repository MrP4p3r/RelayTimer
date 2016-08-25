/*
 * Описание определений из "state.h"
 */

#include "state.h"

State::State()
{
  kb.buttons[0]->onButtonDown(this->b0action);
  kb.buttons[1]->onButtonDown(this->b1action);
  kb.buttons[2]->onButtonDown(this->b2action);
  kb.buttons[3]->onButtonDown(this->b3action);

  kb.buttons[0]->onButtonUp(NULL);
  kb.buttons[1]->onButtonUp(NULL);
  kb.buttons[2]->onButtonUp(NULL);
  kb.buttons[3]->onButtonUp(NULL);
}

State* State::execute()
{
  this->setup();
  return this->loop();
}

