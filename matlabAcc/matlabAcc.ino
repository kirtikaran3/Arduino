int analogx=A0; 
int analogy=A1; 
int analogz=A2; 
int mode=-1; 
int sensorvalue=0; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
Serial.println('a'); 
char a='a';
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  mode=Serial.read(); 
  if(mode='R'){
    sensorvalue=analogRead(analogx); 
    Serial.print("x: "); 
    Serial.println(sensorvalue); 
    sensorvalue=analogRead(analogy); 
    Serial.print("y:"); 
    Serial.println(sensorvalue); 
    sensorvalue=analogRead(analogz); 
    Serial.print("z:"); 
    Serial.println(sensorvalue);
    }
  
  } 
  delay(50);
}
