
#include "myconf.h"

#include "SetT2State.h"

void SetT2State::setup()
{
  Config A = loadConfig();
  hour = A.T2.hour;
  minute = A.T2.minute;
  nextState = (State*)(new StateClock());
}

void SetT2State::save()
{
  Config A = loadConfig();
  A.T2.hour = hour;
  A.T2.minute = minute;
  saveConfig(A);
}
