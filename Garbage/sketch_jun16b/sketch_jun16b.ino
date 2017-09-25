#include "Timer.h" 


Timer Time;
int led1=12;
int led=13;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT); 
pinMode(led1,OUTPUT);
Time.oscillate(led,1000,HIGH);
Time.every(100,Blink);

}

void loop() {
  // put your main code here, to run repeatedly:

Time.update();

} 


void Blink(){
  digitalWrite(led1,HIGH); 
  delay(100); 
  digitalWrite(led1,LOW); 
  delay(100);
}



 
