#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"

//FPS connected to pin 4 and 5 - see previous schemas
FPS_GT511C3 fps(4, 5);

void setup()
{
  Serial.begin(9600);
  delay(100);
  fps.Open();
  //Delete all stored finger print
  fps.DeleteAll();
  //if you want to remove a given id use:
  // fps.DeleteId(id_to_remove)
}

void loop()
{
  delay(10000);
}
