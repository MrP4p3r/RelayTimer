/*
   Модуль содержит класс-кнопку. Класс позволяет устранять дребезг контактов,
   вызывать функцию по нажатию/отжатию кнопки, устанавливать "активное"
   состояние кнопки (кнопка нажата при высоком уровне или при низком).

   Типичное использование:
      void foo(){
        digitalWrite(13, !digitalRead(13));
      }

      Button* b1 = Button(BUTTON1_PIN);

      void setup(){
        b1->setActiveLevel(LOW);
        b1->setDebounceClocks(10);
        b1->onButtonDown(foo);
      }

      void loop(){
        b1->update();
      }
*/

#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON_NCLOCKS_DEFAULT 3

class Button
{
  public:

    Button(int _pin):
      pin(_pin) { pinMode(pin, INPUT); };
    Button(int _pin, int _level):
      pin(_pin), level(_level) { pinMode(pin, INPUT); };
    Button(int _pin, int _level, int _nclocks):
      pin(_pin), level(_level), nclocks(_nclocks) { pinMode(pin, INPUT); };

    void setActiveLevel(int _level)      { level   = _level;   };
    void setDebounceClocks(int _nclocks) { nclocks = _nclocks; };
    void onButtonDown(void (*_foo)())    { onDown  = _foo; onDownArg = NULL; };
    void onButtonUp(void (*_foo)())      { onUp    = _foo; onUpArg   = NULL; };
    void onButtonDown(void (*_foo)(int), int _arg) { onDownArg = _foo; argDown = _arg; onDown = NULL; };
    void onButtonUp(void (*_foo)(int), int _arg)   { onUpArg   = _foo; argUp   = _arg; onUp   = NULL; };

    void update();

  private:

    int pin;                              // вывод, подключенный к кнопке
    int level = LOW;                      // активный уровень (LOW/HIGH)
    int nclocks = BUTTON_NCLOCKS_DEFAULT; // количество клоков для переключения состояния
    int state = 0;                        // логическое состояние кнопки
    int counter = 0;                      // текущий клок

    void (*onDown)();
    void (*onUp)();

    void (*onDownArg)(int);
    void (*onUpArg)(int);

    int argDown = 0;
    int argUp = 0;
};

#endif
