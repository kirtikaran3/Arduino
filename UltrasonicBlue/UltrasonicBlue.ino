#include<LiquidCrystal.h>
LiquidCrystal LCD(12,13,8,7,6,5);
int i;
int a[]={1,2,3,4}; //for L29D
void forward()  {digitalWrite(a[1],HIGH);
    digitalWrite(a[3],HIGH);
  digitalWrite(a[0],LOW);
  digitalWrite(a[2],LOW);
  ultra();
  
  }
  void backward()  {digitalWrite(a[0],HIGH);
  digitalWrite(a[2],HIGH);
  digitalWrite(a[1],LOW);
  digitalWrite(a[3],LOW);
  ultra();
  }
  void left()  {digitalWrite(a[1],HIGH);
  digitalWrite(a[2],HIGH);
  digitalWrite(a[3],LOW);
  digitalWrite(a[0],LOW);
  ultra();
  }
  void right()  {
    digitalWrite(a[3],HIGH);
  digitalWrite(a[0],HIGH);
  digitalWrite(a[2],LOW);
  digitalWrite(a[1],LOW);
  ultra();
  }
void ultra()  {
    digitalWrite(3,0); // to generate pulses via trigger button
  
  
  digitalWrite(3,1);
 // delay(10);
  digitalWrite(3,0);
  int val=pulseIn(2,HIGH); //echo counting on high
 int ret=val/58;
 delay(100);
 LCD.setCursor(0,1);
  LCD.print(ret);
  LCD.print("inches");
  delay(100); 
}
void setup() { for(i=0;i<4;i++) // for motor
{
  pinMode(a[i],OUTPUT);}
Serial.begin(9600);
pinMode(4,OUTPUT);
//pinMode(A4,OUTPUT); // for buzzer
//pinMode(A5,OUTPUT); // led
  pinMode(2,INPUT); // for ultrasonic sensor
  pinMode(3,OUTPUT); // for trigger
 
  LCD.begin(16,2);
  // put your setup code here, to run once:

}


void loop() {
  digitalWrite(4,1);
  if(Serial.available()>0)
  {
    char mot=Serial.read();
    if(mot=='A'){
      forward();
    }
    if(mot=='B')
    {
      backward();
    }
    if(mot=='C')
    {
      left();
     
    }
    if(mot=='D')
    {
      right();
    }
    
  // put your main code here, to run repeatedly:
  }
}
 
  
    
    
  


