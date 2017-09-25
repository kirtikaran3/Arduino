int arr[5]; 
int r;
void setup(){
  
  Serial.begin(250000);  

   
}

void loop(){
  
  while(Serial.available()>0){

     r = Serial.read(); 
    Serial.print("Val : "); 
    Serial.println(r); 

  } 
  
  arr[0]=r;
         
    }
  
  
