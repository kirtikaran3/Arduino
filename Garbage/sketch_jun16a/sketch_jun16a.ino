void setup() {
  // put your setup code here, to run once:
DDRB |=(1<<PINB4); 
DDRB |=(1<<PINB5); 
}

void loop() {
  // put your main code here, to run repeatedly:
PORTB |=(1<<PINB4); 
PORTB|=(1<<PINB5);  
delay(1000);  
PORTB &=~(1<<PINB5);
PORTB &= ~(1<<PINB4); 
delay(1000);

}
