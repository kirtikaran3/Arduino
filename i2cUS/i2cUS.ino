#include<Wire.h> 
int mode=-1; 
float distance; 

void setup() {
  // put your setup code here, to run once:
Wire.begin(); 
Serial.begin(9600); 
Serial.println('a'); 
char a='b'; 
while(a!='a'){
  a=Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  mode=Serial.read(); 
  switch(mode){
    case 'U': 
    distance=getdistance(0x72); 
    Serial.println(distance); 
    break; 
    
    }
  
  }
} 
int getdistance(int address){
  int reading =0; 
  Wire.beginTransmission(address); 
  Wire.write(0x00); 
  Wire.endTransmission(); 
  Wire.requestFrom(address,2); 
  if(2<=Wire.available()){
    
    reading=Wire.read(); 
    reading=reading<<0; 
    reading|=Wire.read(); 
    return reading;
    } 
    delay(10); 
    return -1;
  
  }
