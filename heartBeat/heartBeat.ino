int heart_high, heart_low;
int data[200], i, mapped;
void setup(){
  for(i=2; i<12; i++)
  pinMode(i, OUTPUT);
Serial.begin(115200);
  
}


void loop(){

      heart_high=0;
      heart_low = 1023;
      
      for(i=200; i>0; i--){
        data[i] = data[i-1];
        
      if(data[i]>heart_high)
      heart_high=data[i];
      if(data[i]<heart_low)
      heart_low=data[i];
      }
    
    data[0] = analogRead(0);
    
    mapped = map(data[0], 0, 1023, 0, 600);
    Serial.println(mapped);

  delay(5);
  if((heart_high-heart_low)>150){
  if(data[0] > (heart_high-.95*(heart_high-heart_low)))//this is true if the read is greater than 95% of the span
  digitalWrite(2, HIGH);
  else
  digitalWrite(2,LOW); 
  
  if(data[0] > (heart_high-.9*(heart_high-heart_low)))
  digitalWrite(3, HIGH);
  else
  digitalWrite(3,LOW); 
 
    if(data[0] > (heart_high-.8*(heart_high-heart_low)))
  digitalWrite(4, HIGH);
  else
  digitalWrite(4,LOW); 
    if(data[0] > (heart_high-.7*(heart_high-heart_low)))
  digitalWrite(5, HIGH);
  else
  digitalWrite(5,LOW); 
    if(data[0] > (heart_high-.6*(heart_high-heart_low)))
  digitalWrite(6, HIGH);
  else
  digitalWrite(6,LOW); 
    if(data[0] > (heart_high-.5*(heart_high-heart_low)))
  digitalWrite(7, HIGH);
  else
  digitalWrite(7,LOW); 
    if(data[0] > (heart_high-.4*(heart_high-heart_low)))
  digitalWrite(8, HIGH);
  else
  digitalWrite(8,LOW); 
    if(data[0] > (heart_high-.3*(heart_high-heart_low)))
  digitalWrite(9, HIGH);
  else
  digitalWrite(9,LOW); 
     if(data[0] > (heart_high-.2*(heart_high-heart_low)))
  digitalWrite(10, HIGH);
  else
  digitalWrite(10,LOW); 
     if(data[0] > (heart_high-.1*(heart_high-heart_low)))
  digitalWrite(11, HIGH);
  else
  digitalWrite(11,LOW);  
  
  }//span check
  else
  for(i=2; i<12; i++)//turn all the LEDs off if we're flatlined
  digitalWrite(i,LOW);
  


    

}

