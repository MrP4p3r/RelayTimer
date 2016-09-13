/*
 *  Состояние предоставляет интерфейс для установки времени в формате 24h.
 */

#ifndef SETTIMESTATE_H
#define SETTIMESTATE_H

class StateClock;

class SetTimeState : public State
{
  protected:

    byte substate = 1;

    byte hour;
    byte minute;

    State* nextState;

  public:

    void b1action();

    void b2action();

    void b3action();

    void b4action();

  private:

    // SETUP FUNCTION
    virtual void setup();

    // LOOP FUNCTION
    State* loop();

    virtual void save();

};

#endif
