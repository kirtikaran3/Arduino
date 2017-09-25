int numArr[]={0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0};


void setup(){
  DDRD = 0xff;
  
  } 

 void loop(){

  for(int i=0;i<7;i++){
    PORTD = numArr[i]; 
    delay(1000);
    }
  
  }
