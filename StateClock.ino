
#include "myconf.h"

#include "StateClock.h"
#include "SettingsState.h"

void StateClock::b1action()
{
  nextState = new SettingsState();
}

void StateClock::b2action() { }

void StateClock::b3action()
{
  relay.inv();
  kb->ledGreen()->inv();
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

  RtcDateTime dt1(0,0,0,config.T1.hour,config.T1.minute,1);
  displayTime(dt1);
  delay(3000);

  RtcDateTime dt2(0,0,0,config.T2.hour,config.T2.minute,1);
  displayTime(dt2);
  delay(3000);

  RtcDateTime T = Rtc.GetDateTime();
  int _T = T.Hour()*60 + T.Minute();
  int _T1 = config.T1.hour*60 + config.T1.minute;
  int _T2 = config.T2.hour*60 + config.T2.minute;

  if (_T2 > _T1) {
    if ((_T >= _T1) && (_T < _T2)) {
      if (!relaySwitched) {
        relay.on();
        kb->ledGreen()->on();
        relaySwitched = true;
      }
    } else {
      if (relaySwitched) {
        relay.off();
        kb->ledGreen()->off();
        relaySwitched = false;
      }
    }
  } else {
    if ((_T >= _T2) && (_T < _T1)) {
      if (relaySwitched) {
        relay.off();
        kb->ledGreen()->off();
        relaySwitched = false;
      }
    } else {
      if (!relaySwitched) {
        relay.on();
        kb->ledGreen()->on();
        relaySwitched = true;
      }
    }
  }
}

// LOOP FUNCTION
State* StateClock::loop()
{
  for (;;)
  {
    RtcDateTime T = Rtc.GetDateTime();
    if (!hideDisplay) displayTime(T);
    else displayNone();

    int _T = T.Hour()*60 + T.Minute();
    int _T1 = config.T1.hour*60 + config.T1.minute;
    int _T2 = config.T2.hour*60 + config.T2.minute;

    if (_T1 == _T) {
      if (!relaySwitched) {
        relay.on();
        kb->ledGreen()->on();
        relaySwitched = true;
      }
    } else if (_T2 == _T) {
      if (relaySwitched) {
        relay.off();
        kb->ledGreen()->off();
        relaySwitched = false;
      }
    }

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
