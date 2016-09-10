/*
 * Описание определений из "keyboard.h"
 */

#include "keypad.h"
#include "button.h"
#include "sig.h"

Keypad* Keypad::instance()
{
  if (Keypad::_instance) return Keypad::_instance;
  else return NULL;
}

Keypad* Keypad::instance(int _b1_pin, int _b2_pin, int _b3_pin, int _b4_pin, int _led_red_pin, int _led_green_pin)
{
  if (Keypad::_instance) return Keypad::_instance;
  Keypad::_instance = new Keypad(_b1_pin, _b2_pin, _b3_pin, _b4_pin, _led_red_pin, _led_green_pin);
  return Keypad::_instance;
}

Keypad::Keypad(int _b1_pin, int _b2_pin, int _b3_pin, int _b4_pin, int _led_red_pin, int _led_green_pin)
{
  buttons[0] = new Button(_b1_pin, LOW);
  buttons[1] = new Button(_b2_pin, LOW);
  buttons[2] = new Button(_b3_pin, LOW);
  buttons[3] = new Button(_b4_pin, LOW);

  led_red   = new Sig(_led_red_pin, LOW);
  led_green = new Sig(_led_green_pin, LOW);

  buttons[0]->onButtonDown(Keypad::keyDown, 1);
  buttons[1]->onButtonDown(Keypad::keyDown, 2);
  buttons[2]->onButtonDown(Keypad::keyDown, 3);
  buttons[3]->onButtonDown(Keypad::keyDown, 4);

  buttons[0]->onButtonUp(Keypad::keyUp, 1);
  buttons[1]->onButtonUp(Keypad::keyUp, 2);
  buttons[2]->onButtonUp(Keypad::keyUp, 3);
  buttons[3]->onButtonUp(Keypad::keyUp, 4);
}

void Keypad::keyDown(int a)
{
  Keypad* k = Keypad::_instance;
  if (!k->keyDownBuffer) k->keyDownBuffer = a;
}

void Keypad::keyUp(int a)
{
  Keypad* k = Keypad::_instance;
  if (!k->keyUpBuffer) k->keyUpBuffer = a;
}

int Keypad::keyIsDown()
{
  return !(!keyDownBuffer);
}

int Keypad::keyIsUp()
{
  return !(!keyUpBuffer);
}


int Keypad::getch()
{
  while (!keyDownBuffer);
  return keyDownBuffer;
}


int Keypad::getchUp()
{
  while (!keyUpBuffer);
  return keyUpBuffer;
}

void Keypad::update()
{
  Keypad* k = Keypad::_instance;
  if (k)
  {
    k->buttons[0]->update();
    k->buttons[1]->update();
    k->buttons[2]->update();
    k->buttons[3]->update();
  }
}

Keypad* Keypad::_instance = NULL;
