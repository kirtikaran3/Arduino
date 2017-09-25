


void setup() {
  // put your setup code here, to run once:
 DDRB |= 1 << PINB0;
  DDRB &= ~(1 << PINB1);
  //PORTB |= 1 << PINB1;
    DDRD=0xff;
}

void loop() {
  // put your main code here, to run repeatedly:
 if (bit_is_clear(PINB, 1))
    { 
      PORTD=0xff;
      _delay_ms(1000); //Fast 
      PORTD=0x00; 
      _delay_ms(1000);
    }
    else
    { 
      PORTD=0xAA;
      _delay_ms(1000); //Slow, from previous 
      PORTD=0x55; 
      _delay_ms(1000);
    }
}
