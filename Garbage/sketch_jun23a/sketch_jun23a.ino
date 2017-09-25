int led1=3; 
int led2=4;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

pinMode(led1,OUTPUT); 
pinMode(led2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

    while(Serial.available()>0){

          int ret = Serial.read()-'0'; 
          Serial.print("Value is "); 
          Serial.println(ret);

        if(ret==1){
          digitalWrite(led1,HIGH); 
          digitalWrite(led2,LOW);
          } 
        if(ret==2){
          
          digitalWrite(led2,HIGH); 
          digitalWrite(led1,LOW);
          
          }
          
      
      } 
      


}
