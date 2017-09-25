#include <Wire.h>

int button=12; 
int count=0; 
int previous=HIGH; 
int current;

void setup()
{
  Wire.begin(); 
  Serial.begin(9600); 
}

void loop()
{ 
   current=digitalRead(button); 

    if(previous!=current){

          if(current==HIGH){
            count++; 
            Serial.println(count);
            }
    previous=current; 
    if(count==4){
      count=0;
      }
    } 

   if(count==1){
  Wire.beginTransmission(1);
  Wire.write('H');
  Wire.endTransmission();
 
  delay(100);
  
  Wire.beginTransmission(1);
  Wire.write('L');
  Wire.endTransmission();
 
  delay(100);
   }
 if(count==2){
   Wire.beginTransmission(1);
  Wire.write('H');
  Wire.endTransmission();
 
  delay(500);
  
  Wire.beginTransmission(1);
  Wire.write('L');
  Wire.endTransmission();
 
  delay(500);  
 } 
 if(count==3){
  Wire.beginTransmission(1);
  Wire.write('H');
  Wire.endTransmission();
 
  delay(1000);
  
  Wire.beginTransmission(1);
  Wire.write('L');
  Wire.endTransmission();
 
  delay(1000);
} 
}

