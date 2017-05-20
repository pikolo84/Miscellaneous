#include <Arduino.h>
#include <Miscellaneous.h>

void TimerOn::SetTimer(unsigned long time) {
  _time = time;
}

bool TimerOn::Check(bool input) {
  if (!input) {
    _previousMillis = millis();
    return false;
  }
  else {
    if (millis() >= (_previousMillis+_time))
      return true;
    else
      return false;
  }
}

void TimerOff::SetTimer(unsigned long time) {
  _time = time;
}

bool TimerOff::Check(bool input) {
  if (input) {
    _previousMillis = millis();
    return true;
  }
  else {
    if (millis() >= (_previousMillis+_time))
      return false;
    else
      return true;
  }
}

bool PosEdge::Check (bool input) {
  if (input && !_lastStatus) {
    _lastStatus = input;
    return true;
  }
  else {
    _lastStatus = input;
    return false;
  }
}

bool NegEdge::Check (bool input) {
  if (!input && _lastStatus) {
    _lastStatus = input;
    return true;
  }
  else {
    _lastStatus = input;
    return false;
  }
}
