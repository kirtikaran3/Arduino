#include<avr/interrupt.h>
//#include<SPI.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(50,0);
  pinMode(51,1);            // MOSI
  pinMode(52,1);            //SCK
  pinMode(53,1);            //SS
  SPCR|=(1<<SPE);           // ENABLE SPI 
  SPCR|=(1<<MSTR);          //ENABLE MASTER MODE
  SPCR|=(1<<SPR0);          // devide by 16
 // SPCR|=(1<<SPIE); 
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("in main");
  delay(10);
  transmit();
  
}

void transmit(){
  
  Serial.println("in txfunc");delay(100);
  //Serial.println("ss high");delay(100);
  digitalWrite(53,1);
  //delay(1);
  digitalWrite(53,0);
  SPDR='f';
  Serial.println("waiting");delay(100);
  //while(!(SPSR & (1<<SPIF)));
  digitalWrite(53,1);
  //Serial.println("ss high");delay(100);
  //Serial.print(char(SPDR));
  cli();
}

