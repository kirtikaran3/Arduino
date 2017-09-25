int mp1=2; 
int mn1=3; 
int mp2=4; 
int mn2=5; 

void setup() {
  // put your setup code here, to run once:
pinMode(mp1,OUTPUT); 
pinMode(mn1,OUTPUT); 
pinMode(mp2,OUTPUT); 
pinMode(mn2,OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(mp1,HIGH); 
digitalWrite(mn1,LOW);
digitalWrite(mp2,HIGH); 
digitalWrite(mn2,LOW);
delay(5000);

        digitalWrite(mp1,LOW); 
        digitalWrite(mn1,HIGH);
        digitalWrite(mp2,LOW); 
        digitalWrite(mn2,HIGH);
        delay(5000); 
        
              digitalWrite(mp1,HIGH); 
              digitalWrite(mn1,LOW);
              digitalWrite(mp2,LOW); 
              digitalWrite(mn2,LOW);
              delay(5000); 

                          digitalWrite(mp1,LOW); 
                          digitalWrite(mn1,LOW);
                          digitalWrite(mp2,HIGH); 
                          digitalWrite(mn2,LOW);
                          delay(5000);
}
