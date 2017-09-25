#include <avr/io.h>
void usart_init(void){
  UCSR0B=(1<<TXEN0);
  UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
  UBRR0=0x33;
}
void usart_send(char ch){
  while(!(UCSR0A&(1<<UDRE0)));
  UDR0=ch;


}

void setup() {
  // put your setup code here, to run once:
usart_init();
}

void loop() {
  // put your main code here, to run repeatedly:
usart_send('K');
}
