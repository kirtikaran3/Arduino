void setup() {
  // put your setup code here, to run once:
DDRD |=(1<<PIND0); 
DDRD |=(1<<PIND1); 
DDRD |=(1<<PIND2); 

DDRD &=~(1<<PIND3);
}

void loop() {
  // put your main code here, to run repeatedly:
int ret = digitalRead(3); 
if(ret==HIGH){
  
  } 
  else  {
    
    }

} 



