#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

class State;

class SettingsState : public State
{
  private:

    // SETUP FUNCTION
    void setup();

    // LOOP FUNCTION
    State* loop();

};

#endif
