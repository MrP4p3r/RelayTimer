/*
 * Описание определений из "button.h"
 */

#include "button.h"

void Button::update()
{
  uint8_t q = digitalRead(pin);
  if ( state != (q==level) )
  {
    if ( ++counter==nclocks )
    {
      state = !state;
      counter = 0;
      if (state) if (onDown) onDown();
      if (!state) if (onUp) onUp();
    }
  } else counter = 0;
}

