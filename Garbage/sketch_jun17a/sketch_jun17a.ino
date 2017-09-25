String voice; 


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    
        char c = Serial.read(); 

              if(c=='#'){
                break;
                }              
        
        voice = voice + c;  
        if(voice.length()>0){
        Serial.println(voice); 
        } 
        if(voice=="*lights on"){
          
          } 

          if(voice=="*lights off"){
            
            
            }
        
 voice="";   
    }


} 











