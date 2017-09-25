int motp1=13; 
int motn1=12;
int switch1 =2; 
int motp2=11; 
int motn2=10; 
int switch2=3;
void setup() {
  // put your setup code here, to run once:
pinMode(motp1,OUTPUT);
pinMode(motn1,OUTPUT);
pinMode(motp2,OUTPUT);
pinMode(motn2,OUTPUT);
pinMode(switch2,INPUT);
 
pinMode(switch1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int  irl = digitalRead(switch1); 
int  irr = digitalRead(switch2); 
  if((irl==LOW)&&(irr==LOW)){
    digitalWrite(motp1,HIGH); 
    digitalWrite(motp2,HIGH); 
    digitalWrite(motn1,LOW); 
    digitalWrite(motn2,LOW);
    }  
  if((irl==HIGH)&&(irr==LOW)){
    digitalWrite(motp1,LOW); 
    digitalWrite(motp2,LOW); 
    digitalWrite(motn1,LOW); 
    digitalWrite(motn2,HIGH);
    } 
   if((irl==LOW)&&(irr==HIGH)){
    digitalWrite(motp1,LOW); 
    digitalWrite(motp2,LOW); 
    digitalWrite(motn1,LOW); 
    digitalWrite(motn2,HIGH);
    }  
    
}
