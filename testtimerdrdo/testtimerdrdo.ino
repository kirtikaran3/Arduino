#include <Timer.h>

Timer Time; 

void setup() {
  // put your setup code here, to run once:
//Time.oscillate(13,1000,LOW); 
pinMode(13,OUTPUT); 
pinMode(3,OUTPUT);
//Time.every(1000,Blink); 
Time.after(7000,Exit); 

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(13,HIGH); 
  
Time.update();
} 

void Exit(){
  digitalWrite(13,LOW);
  exit(0);
  } 



  
