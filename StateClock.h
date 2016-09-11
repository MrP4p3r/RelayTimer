#include "myconf.h"

#ifndef STATECLOCK_H
#define STATECLOCK_H

class StateClock : public State
{
  private:

    State* nextState;
    byte hideDisplay;
    Config* config;

  public:

    StateClock(): nextState(0) {};

    void b1action()
    {
      nextState = NULL; // заменить на конструктор нового стейта позже
    }

    void b2action()
    {
      kb->ledGreen()->inv();
    }

    void b3action()
    {
      relay.inv();
    }

    void b4action()
    {
      hideDisplay = !hideDisplay;
    }

  private:

    // SETUP FUNCTION
    void setup()
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
    State* loop()
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
      }
      Serial.println("out of the loop");
    }

};


#endif
