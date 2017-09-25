#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"

FPS_GT511C3 fps(4, 5);

void setup()
{
  Serial.begin(9600);
  delay(100);
  fps.Open();
  fps.SetLED(true);
}

void loop()
{
  // if a finger is on the sensor
  if (fps.IsPressFinger())
  {
    //capture the finger print
    fps.CaptureFinger(false);
    //get the id
    int id = fps.Identify1_N();
  
    if (id <200)
    {
      //finger print recognized: display the id
      Serial.print("Verified ID:");
      Serial.println(id);
    
    }
    else
    {
      
      Serial.println("Finger not found");
      
    }
  }
  else
  {
   
    Serial.println("Please press finger");
  }
  delay(100);
}
