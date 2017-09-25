int pot=A0; 
int ret;
int led=3;
void setup() {
  // put your setup code here, to run once:
pinMode(pot,INPUT); 
pinMode(led,OUTPUT); 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ret=analogRead(pot); 

int value = map(ret,0,1023,0,255);   //ret,ADC(min,max),uP(min,max)

     analogWrite(led,value); 
     Serial.println(value);


}
