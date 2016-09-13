
#include "myconf.h"

#include "SetTimeState.h"
#include "StateClock.h"

void SetTimeState::b1action() { substate--; }

void SetTimeState::b2action() { substate++; }

void SetTimeState::b4action()
{
  // увеличить время
  switch (substate)
  {
    case 1:
      // hour
      hour++;
      break;
    case 2:
      // minute tens
      if (minute == 50) hour++;
      minute = (minute + 10) % 60;
      break;
    case 3:
      // minute ones
      if (minute == 59) hour++;
      minute = (minute + 1) % 60;
      break;
  }
}

void SetTimeState::b3action()
{
  switch (substate)
  {
    case 1:
      // sub hour
      hour = (hour + 23) % 24;
      break;
    case 2:
      // minute tens
      if (minute == 0) hour--;
      minute = (minute + 50) % 60;
      break;
    case 3:
      // set minute ones
      if (minute == 0) hour--;
      minute = (minute + 59) % 60;
      break;
  }
}

// SETUP FUNCTION
void SetTimeState::setup()
{
  RtcDateTime A = Rtc.GetDateTime();
  hour = A.Hour();
  minute = A.Minute();
  nextState = (State*)(new StateClock());
}

// LOOP FUNCTION
State* SetTimeState::loop()
{
  for (;;)
  {
    switch (substate)
    {
      case 0:
        {
          return nextState;
        }
      case 1:
        {
          // set hour
          RtcDateTime dt(0,0,0,hour,minute,0);
          displayTimeSet(dt, 0b0011); // с этой маской моргают часы
          delay(100);
          break;
        }
      case 2:
        {
          // set minute tens
          RtcDateTime dt(0,0,0,hour,minute,0);
          displayTimeSet(dt, 0b1101); // с этой маской моргают десятки
          delay(100);
          break;
        }
      case 3:
        {
          // set minute ones
          RtcDateTime dt(0,0,0,hour,minute,0);
          displayTimeSet(dt, 0b1110); // с этой маской моргают единицы
          delay(100);
          break;
        }
      case 4:
        {
          save();
          return nextState;
        }
    }
    if (kb->keyIsDown())
    {
      int q = kb->getch();
      switch (q)
      {
        case 1: b1action(); break;
        case 2: b2action(); break;
        case 3: b3action(); break;
        case 4: b4action(); break;
      }
    }
  }
}

void SetTimeState::save()
{
  RtcDateTime A = Rtc.GetDateTime();
  RtcDateTime B(A.Year(), A.Month(), A.Day(), hour, minute, 0);
  Rtc.SetDateTime(B);
}
