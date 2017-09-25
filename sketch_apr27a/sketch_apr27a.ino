#include<SoftwareSerial.h> 

String word1;
SoftwareSerial mySerial(8,9);


void setup() {
  // put your setup code here, to run once:
mySerial.begin(9600); 
Serial.begin(9600);
pinMode(12,1);
pinMode(13,1);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(mySerial.available()>0){
    
    char ret = mySerial.read(); 
    if(ret == 'h'){

      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      }  
      if(ret=='l'){
        digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
        }
     if(ret == '$' ){
        char ret = mySerial.read(); 
        word1 = word1 + ret; 
      
      }

    Serial.println(word1);
    delay(100); 
    word1="";
    }

}
