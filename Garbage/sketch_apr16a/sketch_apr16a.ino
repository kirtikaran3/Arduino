int button1=13;
int button2=12;

int mp1=2;
int mn1=3; 
int mp2=4; 
int mn2=6;
void setup() {
  // put your setup code here, to run once:
pinMode(mp1,OUTPUT); 
pinMode(mn1,OUTPUT); 
pinMode(mp2,OUTPUT); 
pinMode(mn2,OUTPUT); 
pinMode(button1,INPUT); 
pinMode(button2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int ret1=digitalRead(button1); 
int ret2=digitalRead(button2);
if((ret1==LOW)&&(ret2==LOW)){

digitalWrite(mp1,HIGH);
digitalWrite(mn1,LOW); 
digitalWrite(mp2,HIGH);
digitalWrite(mn2,LOW); 

} 
}
