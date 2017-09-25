#include<SPI.h> 
int swi=0; 

void setup() {
  // put your setup code here, to run once:

digitalWrite(SS,HIGH); 
SPI.begin(); 
SPI.setClockDivider(SPI_CLOCK_DIV8); 


}

void loop() {
  // put your main code here, to run repeatedly:

char c; 
digitalWrite(SS,LOW); 
  
    if(swi==0){
      for(const char *p="H\n";c=*p;p++) 
      SPI.transfer(c); 
     } 
       else {
      
          for(const char *p="L\n";c=*p;p++) 
          SPI.transfer(c);
      } 
      
digitalWrite(SS,HIGH); 
swi=1-swi; 
delay(1000);

} 




