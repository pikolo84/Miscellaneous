#include <Arduino.h>
#include <Miscellaneous.h>

TimerOn::TimerOn(unsigned long time){
  SetTimer(time);
}

TimerOn::TimerOn(){
}

void TimerOn::SetTimer(unsigned long time) {
  _time = time;
}

bool TimerOn::Check(bool input) {
  if (!input) {
    _previousMillis = millis();
    return false;
  }
  else {
    if (millis()-_previousMillis >= _time)
      return true;
    else
      return false;
  }
}

void TimerOn::Reset(void) {
  _previousMillis = millis();
}

TimerOff::TimerOff(unsigned long time){
  SetTimer(time);
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
    if (millis()-_previousMillis >= _time)
      return false;
    else
      return true;
  }
}

void TimerOff::Reset(void) {
  _previousMillis = millis();
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

bool LinearRamp::handle (float input, float *output, float rampUp, float rampDown, float maxValue) {
  if (input == *output) {
    _previousMillis = millis();
    return true;
  }
  unsigned long elapsedMillis = millis() - _previousMillis;
  if (elapsedMillis == 0)
    return false;
  _previousMillis = millis();
  float tempOutput = *output;
  float tempIncrement = (maxValue / rampUp) * elapsedMillis / 1000.0;
  float tempDecrement = (maxValue / rampDown) * elapsedMillis / 1000.0;
  if (input > tempOutput) {
    if (tempOutput >= 0)
      tempOutput += tempIncrement;
    else
      tempOutput += tempDecrement;
    if (tempOutput > input)
      tempOutput = input;
  }
  else {
    if (tempOutput >= 0)
      tempOutput -= tempDecrement;
    else
      tempOutput -= tempIncrement;
    if (tempOutput < input)
      tempOutput = input;
  }
  *output = tempOutput;
  return false;
}
