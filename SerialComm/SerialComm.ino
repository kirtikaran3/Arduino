int led=16; 

int val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  
  val=(Serial.read()-'0'); 
  
  Serial.println(val);
  delay(500);
  if(val==1){
    digitalWrite(LED_BUILTIN,HIGH);
    } 
    else  
    digitalWrite(LED_BUILTIN,LOW);
}
}
