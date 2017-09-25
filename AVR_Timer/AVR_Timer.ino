

void timer_delay();

void setup(){ 
  DDRB=0xff;  

}
    /* Replace with your application code */
 void loop(){ 
    { 
    PORTB=0xff; 
    timer_delay(); 
    PORTB=0x00; 
    timer_delay();
    }
} 
void timer_delay(){
  
  TCNT0=0xff; 
  
  TCCR0A = 0x02; 
  
  while((TIFR0)&(0x01)==0); 
  TCCR0A=0x00; 
  TIFR0=0x01; 
  
}

