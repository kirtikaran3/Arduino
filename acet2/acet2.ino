int button=13; 
int led=12; 

void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT); 
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

int ret=digitalRead(button); 
if(ret==LOW){
  
  digitalWrite(led,HIGH); 
  
  } 
else  
  digitalWrite(led,LOW);
  
} 








