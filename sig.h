/*
   Модуль содержит класс-светодиод (или что угодно, что управляется через один PIN.
   Класс позволяет изолировать управление через сигналы LOW и HIGH функциями .on, .off, .inv.

   Типичное использование:
      Sig* led = Sig(LED_PIN, LOW);

      void setup(){
        led->on();
      }

      void loop(){
        delay(1000);
        led->inv();
      }
*/

#ifndef SIG_H
#define SIG_H

class Sig
{
  public:

    Sig(int _pin, int _level):
      pin(_pin), level(_level) { pinMode(pin, OUTPUT); digitalWrite(pin, !level); };

    void on();
    void off();
    void inv();

    //void update();

  private:

    int pin;                              // используемый уровень
    int level = LOW;                      // активный уровень (LOW/HIGH)
};

#endif
