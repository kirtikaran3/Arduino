String val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()>0){

    char ret = Serial.read(); 
    if(ret=='#'){
      break;
      } 
      val +=ret;
  }
Serial.print("Val is : "); 
Serial.println(val); 
val=""; 
delay(1000);
}
