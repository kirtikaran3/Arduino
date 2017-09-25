
#ifndef OSCILLOSCOPE_INC
#define OSCILLOSCOPE_INC

//#include "WProgram.h"

void writeOscilloscope(int channel, int value) {
  Serial.print( 0xff, BYTE );                // send init byte
  Serial.print( channel & 0xff, BYTE);       // Send channel ID;
  Serial.print( (value >> 8) & 0xff, BYTE ); // send first part
  Serial.print( value & 0xff, BYTE );        // send second part
}
void writeOscilloscope(int value){
  writeOscilloscope(0,value);
}
#define OSC(c,v) (writeOscilloscope(c,v))
#endif


#include "oscilloscope.h"

#define ANALOG_IN 0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(ANALOG_IN);
  OSC(0,val);
}

*/

