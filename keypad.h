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
 *      k->led_green->switch();
 *    }
 *    
 *    void setup(){
 *      k->buttons[0]->onButtonDown(foo1);
 *    }
 *    
 *    void loop(){
 *      k->update();
 *    }
 */

#include "button.h"
#include "sig.h"

#ifndef KEYPAD_H
#define KEYPAD_H

class Keypad
{
  public:
  
    Keypad(int _b1_pin, int _b2_pin, int _b3_pin, int _b4_pin, int _led_red_pin, int _led_green_pin);

    void update();

    Button *buttons[4];
    Sig *led_green;
    Sig *led_red;

  private:
    
};

#endif
