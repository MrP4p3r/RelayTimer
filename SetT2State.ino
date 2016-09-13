
#include "myconf.h"

#include "SettingsState.h"
#include "SetT2State.h"

void SetT2State::setup()
{
  Config A = loadConfig();
  hour = A.T2.hour;
  minute = A.T2.minute;
  nextState = (State*)(new SettingsState());
}

void SetT2State::save()
{
  Config A = loadConfig();
  A.T2.hour = hour;
  A.T2.minute = minute;
  saveConfig(A);
}
