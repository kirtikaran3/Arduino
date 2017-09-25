int mp1 = 13; 
int mn1 = 11; 
int mp2 = 9; 
int mn2 =8; 
int button1 = 12; 
int button2 = 10;
void setup() {
  // put your setup code here, to run once:
pinMode(mn1,OUTPUT); 
pinMode(button1,INPUT);
pinMode(mp1,OUTPUT); 
pinMode(button2,INPUT);
pinMode(mn2,OUTPUT); 
pinMode(mp2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


int ret1 =  digitalRead(button1); 
int ret2 =  digitalRead(button2); 

if((ret1==HIGH)&&(ret2==HIGH)){
    digitalWrite(mp1,HIGH);   
    digitalWrite(mp2,HIGH);
    digitalWrite(mn1,LOW);   
    digitalWrite(mn2,LOW);
  
  } 
if((ret1==HIGH)&&(ret2==LOW)){
    digitalWrite(mp1,HIGH);   
    digitalWrite(mp2,LOW);
    digitalWrite(mn1,LOW);   
    digitalWrite(mn2,LOW);
  
  } 
  if((ret1==LOW)&&(ret2==HIGH)){
    digitalWrite(mp1,LOW);   
    digitalWrite(mp2,HIGH);
    digitalWrite(mn1,LOW);   
    digitalWrite(mn2,LOW);
  
  }  
  if((ret1==LOW)&&(ret2==LOW)){
    digitalWrite(mp1,LOW);   
    digitalWrite(mp2,LOW);
    digitalWrite(mn1,HIGH);   
    digitalWrite(mn2,HIGH);
  
  } 

 
}
