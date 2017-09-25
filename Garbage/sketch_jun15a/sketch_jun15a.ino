#include "Timer.h"
 
 
Timer t;
int pin = 13;
 
 
void setup()
{
  pinMode(pin, OUTPUT);
  t.pulse(pin, 1 * 60 * 1000, HIGH); // 10 minutes  
  t.pulse(pin,1*60*1000,LOW); 
}
 
 
void loop()
{
  t.update();
}
