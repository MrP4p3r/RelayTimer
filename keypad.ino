/*
 * Описание определений из "keyboard.h"
 */

#include "keypad.h"
#include "button.h"
#include "sig.h"

Keypad::Keypad(int _b1_pin, int _b2_pin, int _b3_pin, int _b4_pin, int _led_red_pin, int _led_green_pin)
{
  buttons[0] = new Button(_b1_pin, LOW);
  buttons[1] = new Button(_b2_pin, LOW);
  buttons[2] = new Button(_b3_pin, LOW);
  buttons[3] = new Button(_b4_pin, LOW);

  led_red   = new Sig(_led_red_pin, LOW);
  led_green = new Sig(_led_green_pin, LOW);

  
}

void Keypad::update()
{
  buttons[0]->update();
  buttons[1]->update();
  buttons[2]->update();
  buttons[3]->update();
}

