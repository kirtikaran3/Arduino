//#include <Adafruit_Fingerprint.h>

#include <FPS_GT511C3.h>
#include <SoftwareSerial.h>

//FPS connected to pin 4 and 5 - see previous schemas
FPS_GT511C3 fps(4, 5);

void setup()
{
  Serial.begin(9600);
  //display messages on the classical serial teminal - DEBUG      
  fps.UseSerialDebug = true; 
  fps.Open();
}

void loop()
{
  //blink the led
  fps.SetLED(true);
  delay(1000);
  fps.SetLED(false);
  delay(1000);
}
