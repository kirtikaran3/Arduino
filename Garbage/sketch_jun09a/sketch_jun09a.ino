
int array1[]={0x3f,0x06};
void setup() {
  // put your setup code here, to run once:
DDRD=0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
int i; 
  for(i=0;i<2;i++){
  
  PORTD=array1[i]; 
  delay(1000);
  
  }

} 







