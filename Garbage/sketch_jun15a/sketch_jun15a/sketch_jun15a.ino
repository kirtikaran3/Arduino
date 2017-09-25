int led=13;  //int nameofcomponent = pin_number; 
int led1=12;
//#define led 13 
int but=11;
void setup() {
  // put your setup code here, to run once:

  pinMode(led,OUTPUT);    //pin number 13 is assinged as output
  pinMode(led1,OUTPUT); 
  pinMode(but,INPUT);
}
void loop() {     //while(1){}
  // put your main code here, to run repeatedly: 

  int ret = digitalRead(but); 

  if(ret==HIGH){ 
    
        digitalWrite(led,HIGH); 
        delay(1000);      //delays are in ms
        digitalWrite(led,LOW);
        delay(1000); 
  } 
else{
  digitalWrite(led1,HIGH); 
  delay(100); 
  digitalWrite(led1,LOW); 
  delay(100);
}
}
