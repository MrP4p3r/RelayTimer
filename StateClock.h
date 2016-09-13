#ifndef STATECLOCK_H
#define STATECLOCK_H

#include "myconf.h"
#include "state.h"

class State;

class StateClock : public State
{
  private:

    State* nextState;
    byte hideDisplay;
    Config config;

  public:

    StateClock(): nextState(0) {};

    void b1action();

    void b2action();

    void b3action();

    void b4action();

  private:

    // SETUP FUNCTION
    void setup();

    // LOOP FUNCTION
    State* loop();

};

#endif
