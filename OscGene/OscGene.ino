int sine[]={0,15,30,45,60,75,90,105,120,135,150,165,180,195,210,225,240,255,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,0}; 
int tri[]={0,45,90,135,180,225,255,225,180,135,90,45,0}; 
int sawtooth[]={0,45,90,135,180,225,225,0}; 

  int previous=LOW; 
  int button=3; 

  int wave=A0; 

  int count=0;
  int reset=0;
          void setup() {
                // put your setup code here, to run once:
                  pinMode(button,OUTPUT); 
                  Serial.begin(9600); 
             }

void loop() {
  // put your main code here, to run repeatedly:

  int current=digitalRead(button); 

  if(current!=previous){
    
    if(current==HIGH){
      
      count++; 
      previous=current;
      Serial.println(count);
      
      } 
      if(count==5){
        
        count=reset;
        }
    
    } 

switch(count){
  
  case 1: 
      
      for(int i=0;i<34;i++){
      analogWrite(A0,sine[i]);
      }
  
          case 2: 

              for(int i=0;i<13;i++){  
              analogWrite(A0,tri[i]);
            }
  
               case 3: 

                  for(int i=0;i<8;i++){
                  analogWrite(A0,sawtooth[i]);
                  } 

                    case 4: 

                        digitalWrite(A0,HIGH); 
                        delay(500); 
                        digitalWrite(A0,LOW); 
                        delay(500);
   
      }
  
  } 
















