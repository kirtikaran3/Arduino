int pin[] = {13,12,11,10,9,8,7};
volatile int state = LOW;

void setup() { 
  for(int i=0;i<7;i++){
    pinMode(pin[i], OUTPUT); 
  } 
    pinMode(2,0);
    attachInterrupt(0, blink1, FALLING);
}

void loop() { 
  for(int i=0;i<7;i++){
    digitalWrite(pin[i],HIGH); 
    delay(1000);
} 
}

void blink1() { 
   for(int i=0;i<7;i++){
    digitalWrite(pin[i],HIGH); 
     delay(10000);
 }
    for(int i=0;i<7;i++){
    digitalWrite(pin[i],LOW); 
     delay(10000);
 }
}
