void setup() {
  // put your setup code here, to run once:
DDRD=0xff;  
DDRB=0x00;
}
void loop() {
  // put your main code here, to run repeatedly:
int retb=digitalRead(13); 
int rett=digitalRead(12); 
int reti=digitalRead(11); 

if((retb==LOW)){
    PORTD=0xff; 
    delay(1000); 
    PORTD=0x00; 
    delay(1000);
} 
     if((rett==LOW)){
            PORTD=0xAA; 
            delay(1000);  

                PORTD=0x55; 
                delay(1000);          
          }  
if((reti==LOW)){
  int i;
  for(i=0;i<256;i++){
    PORTD=i; 
    delay(100);
    }
  }
} 









