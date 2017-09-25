int led=13; 
int but=2;

void setup() {
  // put your setup code here, to run once:

pinMode(led,1); //pinMode(13,1); 
pinMode(but,0); //pinMode(2,0); 

}

void loop() {
  // put your main code here, to run repeatedly:
   int ret = digitalRead(but);//0 or 1

  if(ret==HIGH){
    digitalWrite(13,0);
    } 
   else{    //if(ret==LOW)
     digitalWrite(13,1);
    
    } 

}
