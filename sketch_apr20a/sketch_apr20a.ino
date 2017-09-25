int r =0;
int mot[]={2,3,4,5};
void setup(){
  
  Serial.begin(250000);  

  for(int i=0;i<4;i++){
  pinMode(mot[i],OUTPUT);
 
  }  
}

void loop(){
  
  while(Serial.available()>0){

    int r = Serial.read(); 
    Serial.print("Val : "); 
    Serial.println(r); 

      if(r<100){

        for(int i=1;i<4;i=i+2){

          digitalWrite(mot[i],HIGH);
          } 
          for(int i=0;i<4;i=i+2){
        digitalWrite(mot[i],LOW);
      }
      } 
     if(r>100){

      for(int i=0;i<4;i=i+2){
        digitalWrite(mot[i],HIGH);
      } 
      
        for(int i=1;i<4;i=i+2){

          digitalWrite(mot[i],LOW);
          }
      } 
      
     }
         
    }
  
  
