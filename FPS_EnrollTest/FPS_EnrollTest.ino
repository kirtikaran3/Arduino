#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"


//FPS connected to pin 4 and 5 - see previous schemas
FPS_GT511C3 fps(4, 5);

void setup()
{
  Serial.begin(9600);
  //display messages on the classical serial teminal - DEBUG      
  fps.UseSerialDebug = true; 
  fps.Open();
  //call Enroll to add fingerprint
  enroll();
}


void enroll()
{
  // get the first available id for new finger print
  int enrollid = 0;
  bool usedid = true;
  while (usedid == true)
  {
    usedid = fps.CheckEnrolled(enrollid);
    if (usedid==true) enrollid++;
  }
  
  //enrollment start here with the first free id
  fps.EnrollStart(enrollid);

  
  Serial.print("Press finger to Enroll #");
  Serial.println(enrollid);
  
  // ***** FIRST MEASURE *****
  // wait for finger press
  while(fps.IsPressFinger() == false) delay(100);
  bool bret = fps.CaptureFinger(true);
  int iret = 0;
  if (bret != false)
  {
    //has a finger print captured
    Serial.println("Remove finger");
    // Enroll step 1
    fps.Enroll1(); 
    //wait for finger removed
    while(fps.IsPressFinger() == true) delay(100);
    // ***** SECOND MEASURE *****
    // Now we need to check the finger print 
    // wait for finger press
    Serial.println("Press same finger again");
    while(fps.IsPressFinger() == false) delay(100);
    bret = fps.CaptureFinger(true);
    if (bret != false)
    {
      Serial.println("Remove finger");
      //enroll step 2
      fps.Enroll2();
      //wait for finger removed
      while(fps.IsPressFinger() == true) delay(100);
      // ***** THIRD MEASURE *****
      //Check Again the finger print
      Serial.println("Press same finger yet again");
      while(fps.IsPressFinger() == false) delay(100);
      bret = fps.CaptureFinger(true);
      if (bret != false)
      {
        Serial.println("Remove finger");
        iret = fps.Enroll3();
        if (iret == 0)
        {
          //*** SUCCESS third measure are the same -> NOW finger print is stored
          Serial.println("Enrolling Successfull");
  }
  else
  {
          //*** FAIL For some reason -> NOTHING STORED
          Serial.print("Enrolling Failed with error code:");
    Serial.println(iret);
  }
      }
      else Serial.println("Failed to capture third finger");
    }
    else Serial.println("Failed to capture second finger");
  }
  else Serial.println("Failed to capture first finger");
}

//loop is useless here
void loop()
{
  delay(100000);
}
