#include "StateClock.h"
#include "SetTimeState.h"
#include "myconf.h"

void StateClock::b1action()
{
  nextState = new SetTimeState();
}

void StateClock::b2action()
{
  kb->ledGreen()->inv();
}

void StateClock::b3action()
{
  relay.inv();
}

void StateClock::b4action()
{
  hideDisplay = !hideDisplay;
}

// SETUP FUNCTION
void StateClock::setup()
{
  nextState = 0;
  hideDisplay = 0;
  config = loadConfig();
  RtcDateTime dt1(0,0,0,config->T1.hour,config->T1.minute,1);
  displayTime(dt1);
  delay(3000);
  RtcDateTime dt2(0,0,0,config->T2.hour,config->T2.minute,1);
  displayTime(dt2);
  delay(3000);
}

// LOOP FUNCTION
State* StateClock::loop()
{
  for (;;)
  {
    RtcDateTime A = Rtc.GetDateTime();
    if (!hideDisplay) displayTime(A);
    else displayNone();
    delay(100);

    if (kb->keyIsDown())
    {
      int q = kb->getch();
      switch (q)
      {
        case 1: b1action(); break;
        case 2: b2action(); break;
        case 3: b3action(); break;
        case 4: b4action(); break;
      }
    }

    if (nextState) return nextState;
  }
  Serial.println("out of the loop");
}
