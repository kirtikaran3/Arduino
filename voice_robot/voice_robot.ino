
String voice;
int 

led2 = 3, //Connect LED 2 To Pin #3 
led3 = 4, //Connect LED 3 To Pin #4 
led4 = 10, //Connect LED 4 To Pin #5 
led5 = 11; //Connect LED 5 To Pin #6 
//--------------------------Call A Function-------------------------------//  
void forward(){
 
     digitalWrite(led2, HIGH); 
     digitalWrite(led4, HIGH); 
     digitalWrite(led3, LOW); 
     digitalWrite(led5, LOW); 
}
void backward(){
      
     digitalWrite(led3, HIGH); 
     digitalWrite(led2, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, HIGH);
} 
void left(){
      
     digitalWrite(led3, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, HIGH);
} 
void right(){
      
     digitalWrite(led3, HIGH); 
     digitalWrite(led2, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, LOW);
} 
void wait(){
      
     digitalWrite(led3, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, LOW);
}
//-----------------------------------------------------------------------//  
void setup() {
  Serial.begin(9600);
 // pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT); 
}
//-----------------------------------------------------------------------//  
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
  //----------Control Multiple Pins/ LEDs----------//  
       if(voice == "*forward") {forward();}  //Turn Off All Pins (Call Function)
  else if(voice == "*backward"){backward();} //Turn On  All Pins (Call Function)
  
  //----------Turn On One-By-One----------// 

  else if(voice == "*left") {left();}
  else if(voice == "*right") {right();} 
  else if(voice == "*wait") {wait();}
 
voice="";}} //Reset the variable after initiating
