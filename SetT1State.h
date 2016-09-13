/*
 *  Состояние предоставляет интерфейс для установки Таймера 1 в формате 24h.
 */

#ifndef SETT1STATE_H
#define SETT1STATE_H

#include "SetTimeState.h"

class SetTimeState;

class SetT1State : public SetTimeState
{
  private:

    // SETUP FUNCTION
    void setup();

    // LOOP FUNCTION из SetTimeState

    void save();

};

#endif
