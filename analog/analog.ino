int analog=A0; 
int led=5;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT); 
pinMode(analog,INPUT); 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int readV=analogRead(analog); 
int value=map(readV,0,1023,0,255); 
analogWrite(led,value); 
Serial.println(value);
}
