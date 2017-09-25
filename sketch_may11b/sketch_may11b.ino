

void setup() {
  // put your setup code here, to run once:
pinMode(BUILTIN_LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(BUILTIN_LED,1); 
  delay(100); 
  digitalWrite(BUILTIN_LED,0); 
  delay(100);


}
