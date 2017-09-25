int pot=A0; 
int led=9; 
int ret=0;
void setup() {
  // put your setup code here, to run once:
//pinMode(pot,INPUT); 
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
ret=analogRead(pot); 
//int value=map(ret,0,1023,0,255); 
analogWrite(led,ret); 
delay(500);
}
