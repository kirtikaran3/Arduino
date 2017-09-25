int analogx=A0; 
int analogy=A1; 
int analogz=A2; 
int sensor1; 
int sensor2; 
int sensor3; 
int led[]={2,3,4};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
for(int i=0;i<4;i++){
pinMode(led[i],OUTPUT); 
}
}

void loop() {
  // put your main code here, to run repeatedly:
     sensor1=analogRead(analogx); 
     Serial.print("x: ");
     Serial.println(sensor1); 
     delay(100);  
              Serial.print("y: ");
              sensor2=analogRead(analogy); 
              Serial.println(sensor2); 
              delay(100);  
                  Serial.print("z: ");
                  sensor3=analogRead(analogz); 
                  Serial.println(sensor3); 
                  delay(100); 
if(sensor1<325){
  digitalWrite(led[0],HIGH);
}
  if(sensor2<325){
    digitalWrite(led[1],HIGH);
    } 
    if(sensor3<325){
    digitalWrite(led[2],HIGH);
    }

}
