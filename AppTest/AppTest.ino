
int led[]={13,12,11};
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); 
  
  for(int i=0;i<3;i++){
    pinMode(led[i],OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

  while(Serial.available()>0){

    char ret=Serial.read(); 

      Serial.print("ret is : "); 
      Serial.println(ret);
      
      if(ret=="red"){
        digitalWrite(13,HIGH);
        } 

        else if(ret=="green"){
          digitalWrite(12,HIGH); 
          digitalWrite(13,LOW);
          } 
          else if(ret=="blue"){
            digitalWrite(12,LOW); 
            digitalWrite(13,LOW); 
            digitalWrite(11,HIGH);
            }
     else if(ret=="stop"){
            digitalWrite(12,LOW); 
            digitalWrite(13,LOW); 
            digitalWrite(11,LOW);
            }
    }

}
