int button=2; 
int led=13; 


void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT); 
pinMode(led,OUTPUT); 
attachInterrupt(0,Blink,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,HIGH);

} 
void Blink(){
  
  digitalWrite(led,LOW);
  }
