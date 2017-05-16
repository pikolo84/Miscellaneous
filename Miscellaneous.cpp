#include <Arduino.h>
#include <Miscellaneous.h>

void TimerOn::SetTimer(unsigned long time) {
  _time = time;
}

bool TimerOn::Check(bool input) {
  if (!input)
    _previousMillis = millis();
    return false;
  else {
    if (millis() > (_previousMillis+_time))
      return true;
  }  
}
