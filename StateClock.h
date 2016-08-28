#ifndef STATECLOCK_H
#define STATECLOCK_H

class StateClock : public State
{
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
      kb.led_green->inv();
    }

    static void b2action()
    {
      relay.inv();
    }
    
  private:

    // SETUP FUNCTION
    void setup() {}

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

#endif
