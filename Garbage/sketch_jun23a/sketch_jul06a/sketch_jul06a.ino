int mp1=13; 
int mn1=12; 
int mp2=11; 
int mn2=10;

int button1 = 2; 
int button2 = 3;
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
  
    if((ret1==HIGH)&&(ret2==HIGH)){

      digitalWrite(mp1,HIGH); 
      digitalWrite(mp2,HIGH);
            
  } 
  
 
}
