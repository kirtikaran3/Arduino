int pot=A0; 
int led=3;   
int button=5; 
int state=LOW; 
int count=0;
int sine[]={0,30,50,65,85,110,120,135,165,175,190,220,240,255,240,220,190,175,165,135,120,110,85,65,50,30,0}; 
int tri[]={0,30,45,60,75,90,110,125,140,155,170,185,200,225,255,225,200,185,170,155,140,110,90,75,60,45,30,0}; 
int sawtooth[]={0,30,45,60,75,90,105,120,135,150,165,180,195,210,225,255,0}; 
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT); 
pinMode(pot,INPUT); 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ret=analogRead(pot); 
int state=digitalRead(button);
if(state==HIGH){
  count++; 
  state=LOW; 
  delay(50);
  }
int value=map(ret,0,1023,0,255); 
//Serial.println(value); 

analogWrite(led,value); 

          if(count==1){
                int i;  
                int n=map(value,0,255,0,26);

                        for(i=0;i<n;i++){
                            analogWrite(led,sine[i]); 
                            //Serial.print("n is:"); 
                            Serial.println(sine[i]);
                    }
            }
          
          else if(count==2){ 
              digitalWrite(led,HIGH); 
              delay(value); 
              digitalWrite(led,LOW); 
              delay(value);
            } 
           
           else if(count==3){ 
            int i;  
                int n=map(value,0,255,0,26);
                for(i=0;i<n;i++){
                  analogWrite(led,tri[i]);
                } 
           } 
          
           else if(count==4){ 
            int i;  
                int n=map(value,0,255,0,26);
                for(i=0;i<n;i++){
                  analogWrite(led,sawtooth[i]);
                } 
           }  
           
           else{
            count=0;
            }  
           
    }







    
