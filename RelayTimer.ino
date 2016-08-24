#include <RtcDS3231.h>
#include <TM1637Display.h>

#include "keypad.h"
#include "sig.h"
#include "state.h"
#include "statectl.h"

Keypad kb(7, 8, 9, 10, 11, 12);
Sig relay(6, HIGH);
TM1637Display display(3, 4);
RtcDS3231 Rtc;

void displayTime(const RtcDateTime& dt);
void printDateTime(const RtcDateTime& dt);

class StateClock : public State
{
  private:

    // SETUP FUNCTION
    void setup()
    {
      Serial.println("setup()");
      delay(1000);
      Rtc.Begin();

      RtcDateTime A = RtcDateTime(__DATE__, __TIME__);
      displayTime(A);

      delay(3000);
    }

    // LOOP FUNCTION
    State* loop()
    {
      Serial.println("loop()");
      for (;;)
      {
        RtcDateTime A = Rtc.GetDateTime();
        displayTime(A);
        delay(100);
      }
    }

};

void setup()
{
  // Setup
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Hello!");

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


