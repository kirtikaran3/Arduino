#include "Timer.h" 

Timer Time;
int led=13; 
int led2=12;

int event;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
pinMode(led,OUTPUT); 
pinMode(led2,OUTPUT); 
event=Time.oscillate(led,100,HIGH); 
Time.every(1000,Blink); 
Time.after(10000,stopped);
}

void loop() {
  // put your main code here, to run repeatedly:
Time.update();
}  
void Blink(){
  Time.oscillate(led2,1000,HIGH);
  
  }
void stopped(){
  Time.stop(event);
  digitalWrite(led2,LOW);
  
  }






