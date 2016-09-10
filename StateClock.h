

#ifndef STATECLOCK_H
#define STATECLOCK_H

class StateClock : public State
{
  private:

    static byte nextState;
    static byte hideDisplay;
  
  public:
  
    StateClock()
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

    static void b0action()
    {
      nextState = 1;
    }

    static void b2action()
    {
      relay.inv();
    }

    static void b3action()
    {
      hideDisplay ^= 1;
    }
    
  private:

    // SETUP FUNCTION
    void setup()
    {
      nextState = 0;
      hideDisplay = 0;
    }

    // LOOP FUNCTION
    State* loop()
    {
      for (;;)
      {
        RtcDateTime A = Rtc.GetDateTime();
        displayTime(A);
        delay(100);
      }
    }

};


byte StateClock::nextState = 0;
byte StateClock::hideDisplay = 0;

#endif
