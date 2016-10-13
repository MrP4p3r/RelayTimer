#include "globals.h"

#include "SettingsState.h"
#include "StateClock.h"
#include "SetTimeState.h"
#include "SetT1State.h"
#include "SetT2State.h"

// SETUP FUNCTION
void SettingsState::setup()
{
  // b c 1 2
  uint8_t d[] = {
    0b1111100, // b
    0b1011000, // c
    display.encodeDigit(1), // 1
    display.encodeDigit(2), // 2
  };
  display.setBrightness(0x0f);
  display.setSegments(d);
}

// LOOP FUNCTION
State* SettingsState::loop()
{
  for (;;)
  {
    int q = kb->getch();
    Serial.println(q);
    switch (q)
    {
      case 1: return new StateClock(); break;
      case 2: return new SetTimeState(); break;
      case 3: return new SetT1State(); break;
      case 4: return new SetT2State(); break;
    }
  }
}
