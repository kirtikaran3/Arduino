#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9);//rx tx

byte counter;
byte PWM_Input=128, low, high;
int dataIn;
long Start;

void setup(){
pinMode(3, OUTPUT);
mySerial.begin(9600);
}


void loop(){
analogWrite(3, PWM_Input);  
  dataIn = word(high, low);
  
 if(dataIn>680)
 dataIn=680;
 if(dataIn<400)
 dataIn=400;
 PWM_Input =  map(dataIn, 400, 680, 0, 255);
}
