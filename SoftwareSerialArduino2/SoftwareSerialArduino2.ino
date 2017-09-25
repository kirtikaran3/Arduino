#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11);//rx tx

int i, Message[100], PWM_Value;
byte low, high;

void setup(){
 pinMode(A0,INPUT);
 mySerial.begin(9600);
  Serial.begin(9600);  
}


void loop(){

Serial.println("in loop"); 
delay(100);
delay(10);
  while(mySerial.available()>0){
  if(mySerial.read() == '$'){

    Serial.println("reading");
     Message[i] = mySerial.read();
     if(Message[i]=='#')
     break;
    }

  delay(1);
  low = mySerial.read();
  delay(1);
  high = mySerial.read();  

  PWM_Value = analogRead(0); 
  Serial.println(PWM_Value);
  mySerial.print('$');
  mySerial.print(char(lowByte(PWM_Value)));
  mySerial.print(char(highByte(PWM_Value)));

   
  }
}

