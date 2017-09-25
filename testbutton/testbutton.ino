int button=2; 
int led=13; 

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
