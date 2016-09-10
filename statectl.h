/*
 * Класс контроллер состояний.
 * Возможно стоит заменить это дело на одну функцию, но... НЕТ
 */

#include "state.h"

#ifndef STATECTL_H
#define STATECTL_H

class StateController
{
  public:
    // StateController(){};
    static void loop(State* state);
  private:
};

#endif
