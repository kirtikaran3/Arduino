#include<SoftwareSerial.h> 

String word1;
SoftwareSerial mySerial(8,9);


void setup() {
  // put your setup code here, to run once:
mySerial.begin(9600); 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(mySerial.available()>0){

    mySerial.write('$');  
    delay(1);
    mySerial.write('h'); 
    delay(10);
    mySerial.write('l');
    delay(10);
    }

}
