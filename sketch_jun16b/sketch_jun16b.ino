

void setup() {
  // put your setup code here, to run once:

  DDRD |=(1<<PIND2) ; 
  DDRD |=(1<<PIND7); 
  DDRD &=~(1<<PIND3);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bit_is_set(PIND,3)){
      PORTD = 0x04; 
  } 
  else{ 
    PORTD = 0x80;
  }
}
