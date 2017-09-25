int pot=A0;  
int n=1;
int led[]={1,2,3,4,5,6,7,8,9,10};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);    
pinMode(pot,INPUT);
for(int i=0;i<8;i++){
  pinMode(led[i],OUTPUT); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

int ret=analogRead(pot); 
int value=map(ret,0,1023,0,255); 

int number=(value/25); 
Serial.println(number);
for(int i=0;i<number;i++){
  
  digitalWrite(led[i],HIGH); 
  digitalWrite(led[i-n],LOW);
 
  }
}



















