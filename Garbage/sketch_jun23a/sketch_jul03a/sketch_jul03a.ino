
void timerdelay(); 

void setup() {
  // put your setup code here, to run once:
  TCNT0 = 0xFF; 
  TCCR0B |=(1<<CS02)|(1<<CS00);
  TIMSK0 |=(1<<TOIE0); 
  
  DDRD=0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
      PORTD=0xFF; 
      timerdelay(); 
      PORTD=0x00; 
      timerdelay();
} 

void timerdelay(){
  
  while((TIFR0 & (1<<TOV0))==0);
  TCNT0 = 0xFF;
  TIFR0 &=~(1<<TOV0);
  
}
