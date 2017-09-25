
void setup() {

  DDRD |=(1<<PIND7);
  DDRD &=~(1<<PIND2);
}

void loop() {

  if(bit_is_clear(PIND,2)){

        PORTD |=(1<<PIND7);
    } 
   else{

      PORTD &=~(1<<PIND7);
    
    } 

}
