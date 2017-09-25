int pot=A0;
int i;
int button=3; 
int previous=LOW; 
int count=0;  
int output=5;
int tri[]={0,15,30,45,60,75,90,105,120,135,150,165,170,185,190,205,225,255,225,205,190,185,170,165,150,135,120,105,90,75,60,45,30,15,0}; 
int sine[]={0,35,50,75,90,115,135,160,190,210,230,255,225,210,190,160,135,115,90,75,50,35,0};
int sqr[]={0,255,0}; 
int sawtooth[]={0,15,30,45,60,75,90,105,120,135,150,165,170,185,190,205,225,255,0};
void setup() {
  // put your setup code here, to run once:
pinMode(button,INPUT); 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ret=digitalRead(button);  
delay(100);
if((ret!=previous)){ 
  if((ret==HIGH)){
  count++; 
  Serial.println(count); 
  }
  previous=ret;
  }  
        int ret=analogRead(pot); 
        int value=map(ret,0,1023,0,255); 
        int n=map(value,0,1023,0,)  
        if(count==1){
          for(i=0;i<n;i++){
            analogWrite(output,sine[i]); 
            Serial.print(sine[i]);
            }    
          }   
              
          
} 














