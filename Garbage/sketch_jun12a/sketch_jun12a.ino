int but=13; //#define led 13
int count=0; 
int pst=LOW; 

void setup() {
  // put your setup code here, to run once:

pinMode(but,INPUT);      //pinMode(13,1)  1--output 0---input
Serial.begin(9600); 
DDRD=0xFF;
}

void loop() {
  // put your main code here, to run repeatedly: 
  PORTD=0xFF; 
  delay(1000); 
  PORTD=0x00; 
  delay(1000);
int cst = digitalRead(but); 
if(cst != pst){ 
if(cst==LOW){
  count++;
  }
Serial.print("Val : "); 
Serial.println(count);

} 
pst=cst;
}
