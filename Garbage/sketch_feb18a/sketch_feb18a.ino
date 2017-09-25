void setup() {
  // put your setup code here, to run once:
pinMode(13,INPUT); 
pinMode(12,INPUT); 

pinMode(11,OUTPUT);  //in1 
pinMode(10,OUTPUT); //in2 
pinMode(9,OUTPUT); //in3 
pinMode(8,OUTPUT); //in4
}

void loop() {
  // put your main code here, to run repeatedly:
int val; 
int ret; 

ret = digitalRead(13); 
val = digitalRead(12); 

  if(ret==LOW && val==LOW){ 

    //in1 -- 11 =HIGH; in3 -- 9 = HIGH
    digitalWrite(11,HIGH); 
    digitalWrite(10,LOW); 
    digitalWrite(9,HIGH); 
    digitalWrite(8,LOW);
    
    }   

} 





