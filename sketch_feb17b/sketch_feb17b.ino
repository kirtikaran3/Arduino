void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);  //0 stands for input
                  // 1 stands for output.
  pinMode(12,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value;
  value=digitalRead(12);
  if(value==1){digitalWrite(13,1);}
  if(value==0){digitalWrite(13,0);} 
  }
