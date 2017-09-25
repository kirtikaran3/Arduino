int pot=A0; 


void setup() {
  // put your setup code here, to run once:

pinMode(pot,INPUT); 
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int ret=analogRead(pot); 
int value=map(ret,0,1023,0,255);   //ret,ADC(min,max),uP(min,max)

Serial.print("Read value : "); 
Serial.println(value);
} 




