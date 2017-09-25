void setup() {
  // initialize the serial communication:
  Serial.begin(2400);
  pinMode(4, INPUT); // Setup for leads off detection LO +
  pinMode(5, INPUT); // Setup for leads off detection LO -
  DDRK=0xFF;
}

void loop() {
  
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
      Serial.println(analogRead(2));
  }
  //Wait for a bit to keep serial data from saturating
  //delay(1);
}

