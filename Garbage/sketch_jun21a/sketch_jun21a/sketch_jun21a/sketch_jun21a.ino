String voice;
void setup() {
  // put your setup code here, to run once:1

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

    while(Serial.available()>0){

        char a = Serial.read(); 

        if(a=='#'){
          break;
          }
        voice +=a;
    }
Serial.println(voice); 
delay(2000);
voice="";
}
