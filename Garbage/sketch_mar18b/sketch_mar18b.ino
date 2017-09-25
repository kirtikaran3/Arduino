int but1=13; 
int but2=12; 
int mp1=2; 
int mn1=3; 
int mp2=4; 
int mn2=5;

void setup() {
  // put your setup code here, to run once:
pinMode(but1,INPUT); 
pinMode(but2,INPUT); 
pinMode(mn1,OUTPUT); 
pinMode(mp1,OUTPUT); 
pinMode(mn2,OUTPUT); 
pinMode(mp2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int ret1=digitalRead(but1); 
int ret2=digitalRead(but2); 

if((ret1==LOW)&&(ret2==LOW)){
  digitalWrite(mp1,HIGH); 
  digitalWrite(mn1,LOW);  
   digitalWrite(mp2,HIGH); 
  digitalWrite(mn2,LOW); 
  } 
  if((ret1==HIGH)&&(ret2==LOW)){
  digitalWrite(mp1,HIGH); 
  digitalWrite(mn1,LOW);  
   digitalWrite(mp2,LOW); 
  digitalWrite(mn2,LOW); 
  } 
  if((ret1==LOW)&&(ret2==HIGH)){
  digitalWrite(mp1,LOW); 
  digitalWrite(mn1,LOW);  
   digitalWrite(mp2,HIGH); 
  digitalWrite(mn2,LOW); 
  }
if((ret1==HIGH)&&(ret2==HIGH)){
  digitalWrite(mp1,LOW); 
  digitalWrite(mn1,HIGH);  
   digitalWrite(mp2,LOW); 
  digitalWrite(mn2,HIGH); 
  }
}
