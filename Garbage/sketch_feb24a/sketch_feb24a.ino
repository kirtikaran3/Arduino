

void setup() {
  // put your setup code here, to run once:

  pinMode(16,1); 
  pinMode(15,1); 
  pinMode(14,1); 
  pinMode(13,1); 
  pinMode(12,1); 
  pinMode(11,1); 
  pinMode(10,1); 
  pinMode(9,1); 
}

void loop() {
  // put your main code here, to run repeatedly: 

  digitalWrite(16,1);
  delay(1000); 
  digitalWrite(16,0);
  delay(1000); 
  digitalWrite(14,1); 
  delay(1000); 
  digitalWrite(14,0);
  delay(1000);

}
