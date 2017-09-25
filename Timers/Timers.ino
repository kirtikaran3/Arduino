#include <TimerOne.h>

void setup()
{ 
  pinMode(3,OUTPUT);
  pinMode(10, OUTPUT);
  Timer1.initialize(500000);         // initialize timer1, and set a 1/2 second period
  Timer1.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle
  //Timer1.attachInterrupt(callback);  
  Timer1.attachInterrupt(blinkL);// attaches callback() as a timer overflow interrupt
}
 
void callback()
{
  digitalWrite(10, digitalRead(10) ^ 1);
} 
void blinkL(){
digitalWrite(3,HIGH); 
delay(100); 

}
 
void loop()
{
  // your program here...
}
