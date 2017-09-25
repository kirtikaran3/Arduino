int led=13; 
char ret;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
pinMode(led,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()>0){
  
  ret=Serial.read();
  Serial.println(ret);
   
  if(ret=='H'){
    digitalWrite(led,HIGH);
    } 
   if(ret=='L'){
    digitalWrite(led,LOW);
    }
}
}



