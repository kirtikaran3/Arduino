#include "oscilloscope.h"

#define ANALOG_IN 0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(ANALOG_IN);
  OSC(0,val); // Draws pretty white line thanks to Sofian Audry
  OSC(1, val*1.3); // Overlaps a red line version of the signal amplified by a third.
}
