#include<Wire.h>
void setup() {
  // put your setup code here, to run once:
Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  Wire.beginTransmission(1); 
  Wire.write('H'); 
  Wire.endTransmission();

}
