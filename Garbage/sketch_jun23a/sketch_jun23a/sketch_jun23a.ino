#include "Timer.h" 

Timer time1;

void setup() {
  // put your setup code here, to run once:

  pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT); 

  time1.every(1000,blink1); 
  time1.after(3000,toggle); 
  time1.oscillate(13,50,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
time1.update();
} 
void blink1(){
  
  digitalWrite(2,HIGH);  
  digitalWrite(3,HIGH);
  delay(1000);
  
  digitalWrite(2,LOW);  
  digitalWrite(3,LOW);
  delay(1000);
  
  }
void toggle(){
  
  digitalWrite(2,HIGH);  
  digitalWrite(3,LOW);
  delay(1000);
  digitalWrite(2,LOW);  
  digitalWrite(3,HIGH);
  delay(1000);
  
  }


