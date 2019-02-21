#include <Miscellaneous.h>

LinearRamp testRamp;
float rampIn = 100.0, rampOutput = -100.0;

void setup (void) {
  Serial.begin(115200);
  Serial.flush();
  Serial.println("RAMP TEST");
}

void loop (void) {
    if (testRamp.handle(rampIn, &rampOutput, 1.0, 2.0, 1.0))
      Serial.println("SETPOINT REACHED");
    Serial.printf("IN: %f OUT: %f\n", rampIn, rampOutput);
    delay (2000);
}