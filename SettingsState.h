/*
 *  Навигация по настройкам устройства
 *  Кнопка 1 - переход в режим часов
 *  Кнопка 2 - переход в режим установки времени
 *  Кнопка 3 - переход в режим установки Т1
 *  Кнопка 4 - переход в режим установки Т2
 */

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
