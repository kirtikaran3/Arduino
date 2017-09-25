#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9);//rx tx

byte counter;
byte PWM_Input=255, low, high;
int dataIn;
long Start;

void setup(){
pinMode(3, OUTPUT);
mySerial.begin(9600);
}


void loop(){

mySerial.print("$");
mySerial.print('#');

Start = millis();
while(millis()-Start<100){
 delay(1);

while(mySerial.read()=='$'){
  delay(1);
  low = mySerial.read();
  delay(1);
  high = mySerial.read();
  break;} 
  }  

  int dataIn = word(high, low);  
  PWM_Input =  map(dataIn, 0, 1023, 0, 255);
  analogWrite(3, PWM_Input);
}
