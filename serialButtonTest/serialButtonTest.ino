#include<SoftwareSerial.h>

SoftwareSerial serial(8,9); 
int sread; 
int button=2;
void setup() {
  // put your setup code here, to run once:
serial.begin(9600); 
pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(serial.available()>0){
  if(serial.read()=='$'){
    sread=serial.read();
    if(sread=='#'){
      break;
      }
    } 
    delay(1); 
    
    int i=serial.read();
    int ret=digitalRead(button); 
    
    if(ret==HIGH){
      
      } 
    if(ret==LOW){
      
      }  
  }

}
