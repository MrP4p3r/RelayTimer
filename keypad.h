/*
 * Модуль содержит класс-клавиатуру с двумя светодиодами (общий анод) и
 * четырьмя кнопками (активны по низкому уровню).
 *
 * Типичное использование:
 *
 *    Keyboard* k = Keyboard(
 *      BUTTON1_PIN, BUTTON2_PIN, BUTTON3_PIN, BUTTON4_PIN,
 *      LED_RED_PIN, LED_GREEN_PIN
 *    );
 *
 *    void foo1(){
 *      k.ledGreen()->on();
 *    }
 *
 *    void foo2(){
 *      k.ledGreen()->off();
 *    }
 *
 *    void setup(){ }
 *
 *    void loop(){
 *      if (k.keyIsDown())
 *        switch (k.getch()) {
 *          case 2: foo1();
 *          default: foo2();
 *        }
 *    }
 */

#include "button.h"
#include "sig.h"

#ifndef KEYPAD_H
#define KEYPAD_H

class Keypad
{
  public:

    static void update();
    static Keypad* instance(int _b1_pin, int _b2_pin, int _b3_pin, int _b4_pin, int _led_red_pin, int _led_green_pin);
    static Keypad* instance();

    // Получить указатель на индикаторы
    Sig* ledGreen() { return Keypad::led_green; };
    Sig* ledRed() { return Keypad::led_red; };

    // Методы для проверки нажатий/отжатий
    int keyIsDown();
    int keyIsUp();
    int getch();
    int getchUp();

  private:
    // Конструктор и статический указатель на экземпляр класса (Keypad - синглтон)
    Keypad(int _b1_pin, int _b2_pin, int _b3_pin, int _b4_pin, int _led_red_pin, int _led_green_pin);
    static Keypad* _instance;

    // Кнопки и индикаторы клавиатуры
    Button *buttons[4];
    Sig *led_green;
    Sig *led_red;

    // Callback для нажатия/отжатия кнопки
    static void keyDown(int a);
    static void keyUp(int a);

    // Кнопки, нажатая/отжатая в данный момент времени (или NULL)
    int keyDownBuffer = 0;
    int keyUpBuffer = 0;
};

#endif
