#include<avr/interrupt.h>
char c;
void setup() {
  // put your setup code here, to run once:
  pinMode(50,1);
  pinMode(51,0);
  pinMode(52,0);
  pinMode(53,0);
  pinMode(13,1);
  SPCR|=(1<<SPE);
  SPCR|=(1<<SPIE);
  Serial.begin(9600);
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("IN MAIN");  
  if(c=='f'){ myblink(); }
  Serial.println(c);delay(10);
}

ISR(SPI_STC_vect){

/* Wait for reception complete */
Serial.println("receiving");
delay(5);
//while(!(SPSR & (1<<SPIF))){}
/* Return Data Register */
c=SPDR;
}
void myblink(){
  digitalWrite(13,0);
  delay(100);
    digitalWrite(13,1);
  delay(100);
}

