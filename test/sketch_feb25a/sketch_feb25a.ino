int but1=2; 
int but2=3; 
int led1=13; 
int led2=12;

void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT); 
pinMode(led2,OUTPUT); 
pinMode(but1,INPUT); 
pinMode(but2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int ret=digitalRead(but1); 
int val=digitalRead(but2);

if(ret==LOW){
  digitalWrite(led1,HIGH);
   }  
   else
    digitalWrite(led1,LOW);
if(val==LOW){
  digitalWrite(led2,HIGH);
   }  
   else 
    digitalWrite(led2,LOW);
if((ret==LOW)&&(val==LOW)){
  digitalWrite(led1,HIGH); 
  delay(100); 
  digitalWrite(led1,LOW); 
  delay(100); 
  digitalWrite(led2,HIGH); 
  delay(1000); 
  digitalWrite(led2,LOW); 
  delay(1000);
   } 
 
}
