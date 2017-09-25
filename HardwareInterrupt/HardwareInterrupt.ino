int butint1=0;  //pin2 
//int butint2=3; //pin3
volatile int bled=0;
int led1=13; 
int led2=12;
void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT); 
pinMode(led2,OUTPUT);
attachInterrupt(0,blinkL,LOW); 
//attachInterrupt(butint2,toggle,RISING); 

}
void blinkL(){

bled=1;
} 
void loop() {
  // put your main code here, to run repeatedly:
if(bled==1){
digitalWrite(led1,HIGH); 

digitalWrite(led2,HIGH); 
delay(1000);

digitalWrite(led1,LOW); 

digitalWrite(led2,LOW); 
delay(1000);
  
} 
}


//void toggle(){
//  
//digitalWrite(led1,HIGH); 
//
//digitalWrite(led2,LOW); 
//delay(1000);
//
//digitalWrite(led1,LOW); 
//
//digitalWrite(led2,HIGH); 
//delay(1000);
//  
//  
//  }

