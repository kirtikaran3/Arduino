#include<SPI.h> 
char buf[100]; 
byte pos; 
boolean done; 

void setup() {
  // put your setup code here, to run once:

Serial.begin(115200); 
pinMode(MISO,OUTPUT); 
SPCR |=_BV(SPE); 
pos=0; 
done=false; 

SPI.attachInterrupt();
}

void loop() {
  // put your main code here, to run repeatedly:
if(done){
  
  buf[pos]=0; 
  Serial.println(buf); 
  pos=0; 
  done=false;
  }
} 
ISR(SPI_STC_vect){
  
  byte c=SPDR; 
  if(pos<sizeof buf){
    buf[pos++]=c; 
    
    } 
    if(c=='\n'){
      done=true;
      }
  }






