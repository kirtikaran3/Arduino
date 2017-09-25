int count=0; 
int button=13; 
int previous=LOW;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int current=digitalRead(button); 

  if(current!=previous){

          if(current==HIGH){ 
 
              count++;
              Serial.println(count);
            }   
      previous=current;
    }
}
