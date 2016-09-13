
#include "myconf.h"

#include "SetT1State.h"

void SetT1State::setup()
{
  Config* A = loadConfig();
  hour = A->T1.hour;
  minute = A->T1.minute;
  nextState = (State*)(new StateClock());
}

void SetT1State::save()
{
  Config* A = loadConfig();
  A->T1.hour = hour;
  A->T1.minute = minute;
  saveConfig(A);
}
