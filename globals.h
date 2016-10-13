
#include <TimerOne.h>

#include <RtcDS3231.h>
#include <TM1637Display.h>

#include "keypad.h"
#include "sig.h"

#ifndef GLOBALS_H
#define GLOBALS_H

extern Keypad *kb;
extern Sig relay;
extern TM1637Display display;
extern RtcDS3231 Rtc;

void displayTime(const RtcDateTime& dt);
void displayNone();
void printDateTime(const RtcDateTime& dt);

#endif
