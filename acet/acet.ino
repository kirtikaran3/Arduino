int led=13;       //#define led 13
int led1=12; 
int led2=11; 
int led3=10; 
int led4=9;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT); 
pinMode(led1,OUTPUT); 
pinMode(led2,OUTPUT); 
pinMode(led3,OUTPUT); 
pinMode(led4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,HIGH); 
digitalWrite(led1,LOW); 
digitalWrite(led2,HIGH); 
digitalWrite(led3,LOW); 
digitalWrite(led4,HIGH); 
delay(1000); 
digitalWrite(led,LOW); 
digitalWrite(led1,HIGH); 
digitalWrite(led2,LOW); 
digitalWrite(led3,HIGH); 
digitalWrite(led4,LOW); 
delay(1000);
}
