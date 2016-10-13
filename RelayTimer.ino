#include "globals.h"

#include <TimerOne.h>

#include <RtcDS3231.h>
#include <TM1637Display.h>

#include "keypad.h"
#include "sig.h"
#include "state.h"
#include "statectl.h"

Keypad *kb = Keypad::instance(7, 8, 9, 10, 11, 12);
Sig relay(6, HIGH);
TM1637Display display(3, 4);
RtcDS3231 Rtc;

void displayTime(const RtcDateTime& dt);
void displayNone();
void printDateTime(const RtcDateTime& dt);

#include "StateClock.h"

void setup()
{
  // Setup
  Serial.begin(9600);
  Serial.println((int)&kb);
  Rtc.Begin();
  while (!Serial);

  Serial.println("Hello!");
  Timer1.initialize(15000);
  Timer1.attachInterrupt(kb->update);

  // Вызов главного цикла
  StateController::loop(&StateClock());
  Serial.println("end");
}

void loop() {}


void displayTime(const RtcDateTime& dt)
{
  uint8_t d[] = {0, 0, 0, 0};
  bool dots = dt.Second() & 1;
  d[3] = display.encodeDigit(dt.Minute() % 10);
  d[2] = display.encodeDigit(dt.Minute() / 10);
  d[1] = display.encodeDigit(dt.Hour() % 10);
  d[0] = display.encodeDigit(dt.Hour() / 10);
  d[1] |= dots << 7;

  display.setBrightness(0x0f);
  display.setSegments(d);
}

void displayTimeSet(const RtcDateTime& dt, byte mask)
{
  uint8_t d[] = {0, 0, 0, 0};
  bool blink = millis()/600%2;
  d[3] = (mask&1 || blink) ? display.encodeDigit(dt.Minute() % 10) : 0;
  d[2] = (mask&2 || blink) ? display.encodeDigit(dt.Minute() / 10) : 0;
  d[1] = (mask&4 || blink) ? display.encodeDigit(dt.Hour() % 10) : 0;
  d[0] = (mask&8 || blink) ? display.encodeDigit(dt.Hour() / 10) : 0;
  d[1] |= 1 << 7;

  display.setBrightness(0x0f);
  display.setSegments(d);
}

void displayNone()
{
  uint8_t d[] = {0, 0, 0, 0};
  display.setBrightness(0x0);
  display.setSegments(d);
}

#define countof(a) (sizeof(a) / sizeof(a[0]))
void printDateTime(const RtcDateTime& dt)
{
  char datestring[20];

  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Day(),
             dt.Month(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  Serial.println(datestring);
}
