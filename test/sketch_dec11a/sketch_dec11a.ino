
void setup() {
  // put your setup code here, to run once:
DDRD=0xff;
}

void loop() {
  // put your main code here, to run repeatedly:
PORTD=0xff; 
delay(1000); 
PORTD=0x00; 
delay(1000);
}
