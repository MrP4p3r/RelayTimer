/*
 *  Состояние предоставляет интерфейс для установки Таймера 2 в формате 24h.
 */

#ifndef SETT2STATE_H
#define SETT2STATE_H

#include "SetTimeState.h"

class SetTimeState;

class SetT2State : public SetTimeState
{
  private:

    // SETUP FUNCTION
    void setup();

    // LOOP FUNCTION из SetTimeState

    void save();

};

#endif
