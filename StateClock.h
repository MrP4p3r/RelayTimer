

#ifndef STATECLOCK_H
#define STATECLOCK_H

class StateClock : public State
{
  private:

    State* nextState;
    byte hideDisplay;

  public:

    StateClock(): nextState(0) {};

    void b0action()
    {
      nextState = NULL; // заменить на конструктор нового стейта позже
    }

    void b2action()
    {
      relay.inv();
    }

    void b3action()
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


#endif
