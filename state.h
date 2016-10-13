/*
 * Модуль содержит базовый класс состояния интерфейса
 * Состояние имеет две основных метода: setup и loop
 *
 * Назначения методов аналогичны тем самым функциям setup и loop
 * с тем лишь замечанием, что loop не вызывается циклом, но
 * должен сам содержать цикл:
 *
 * class MyState: public State{
 *   void setup(){
 *     pinMode(13,WRITE);
 *   }
 *   State* loop(){
 *     for(;;){
 *       digitalWrite(13,HIGH);
 *       delay(1000);
 *       digitalWrite(13,LOW);
 *       delay(1000);
 *     }
 *     return NULL;
 *   }
 *
 * Для корректной работы контроллера состояний (statectl.h)
 * метод loop() должен возвращать указатель на следующее состояние (или NULL).
 */

#ifndef STATE_H
#define STATE_H

class State
{
  public:
    State() {};
    virtual ~State() {};
    virtual State* execute();

  private:
    virtual void setup() {};
    virtual State* loop() {};
};

#endif
