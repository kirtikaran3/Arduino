int analog1=A0; 
int analog2=A1; 
int analog3=A2;
int mode =-1;
unsigned int sensorvalue1; 
unsigned int sensorvalue2; 
unsigned int sensorvalue3; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
char a='o'; 
  while(a != 'a'){
    a-Serial.read();
    }
}

void loop() {
  // put your main code here, to run e:
if(Serial.available()>0){
  
  mode=Serial.read(); 
  if(mode== 'R'){
    sensorvalue1=analogRead(analog1);
    Serial.println(sensorvalue1); 
    sensorvalue2=analogRead(analog2); 
    Serial.println(sensorvalue2); 
    sensorvalue3=analogRead(analog3); 
    Serial.println(sensorvalue3);
    }
  }
}
