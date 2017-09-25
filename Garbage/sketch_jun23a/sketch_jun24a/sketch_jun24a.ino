int led=13;


void setup() {
  // put your setup code here, to run once:

  pinMode(led,OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(4),blink1,RISING);
  
}

void loop() {
  // put your main code here, to run repeatedly:

    digitalWrite(led,HIGH);

} 
void blink1(){
  
    digitalWrite(led,HIGH); 
    delay(100000); 
    digitalWrite(led,LOW); 
    delay(100000);
  
  }

