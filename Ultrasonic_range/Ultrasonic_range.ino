int pingpin=7; 
int echo=8; 
int mode=-1; 
float distance; 
long duration;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
Serial.println('a'); 
char a = 'b'; 
while(a!='a'){
  a=Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  
  mode=Serial.read(); 
  switch(mode){
    case 'P': 
    duration=getpingduration(pingpin); 
    distance=microsecondstocentimeter(duration); 
    Serial.println(distance); 
    break;
    
    }
  }
} 
long getpingduration(int pingpin){
  long dura; 
  pinMode(echo,OUTPUT); 
  digitalWrite(echo,LOW); 
  delayMicroseconds(2); 
  digitalWrite(echo,HIGH); 
  delayMicroseconds(5); 
  digitalWrite(echo,LOW);
  pinMode(pingpin,INPUT); 
  dura=pulseIn(pingpin,HIGH);  
  return dura;
  } 
long microsecondstocentimeter(long microseconds){
  
  return microseconds/29/2;
  }




  







