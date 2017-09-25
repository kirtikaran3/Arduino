int LMen=5;//enable of LEFT motor
int RMen=6;//enable of Right motor
int LM1=3;//direction pin1 of first motor
int LM2=4;//direction pin2 of first motor
int RM1=7;//direction pin1 of right motor
int RM2=8;//direction pin1 of right motor
int N1=A7;//node detector1
int N2=A4;//node detector2
int T1=A6;//tracing sensor1
int T3=A5;//tracing sensor2
int LED=13;//arduino LED
int sensitivity=400;//threshold for sensors

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(LMen, OUTPUT);
pinMode(RMen, OUTPUT);
pinMode(LM1, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(RM1, OUTPUT);
pinMode(RM2, OUTPUT);
pinMode(N1,INPUT);
pinMode(N2,INPUT);
pinMode(T1,INPUT);
pinMode(T3,INPUT);
digitalWrite(LM1, LOW);//direction forward
digitalWrite(LM2, HIGH);//direction forward
digitalWrite(RM1, HIGH);//direction forward
digitalWrite(RM2, LOW);//direction forward
digitalWrite(LMen, LOW);
digitalWrite(RMen, LOW);
Serial.begin(9600);
}

void loop()
{
  if(analogRead(N1)>sensitivity && analogRead(N2)>sensitivity && analogRead(T1)>sensitivity  && analogRead(T3)>sensitivity )
    {
      digitalWrite(LED,HIGH);
      right90();
    } 
  else
  {
    followline();
   digitalWrite(LED,LOW);
  }
}


void followline()
{
  if(analogRead(T1)>sensitivity && analogRead(T3)<sensitivity)
  {
    left();
  }
  else if(analogRead(T1)<sensitivity && analogRead(T3)>sensitivity)
  {
    right();
  }
  else
  {
    straight();
  }
}

void straight()
{
  digitalWrite(LMen,HIGH);
  digitalWrite(RMen,HIGH);
}


void left()
{
  digitalWrite(LMen,LOW);
  digitalWrite(RMen,HIGH);
}

void right()
{
  digitalWrite(LMen,HIGH);
  digitalWrite(RMen,LOW);
}

void right90()
{
  int i=1;
  right();
  straight();
  while(analogRead(N1)<sensitivity && analogRead(N2)<sensitivity && i==1)
  {
    right();
    if(analogRead(T1)>sensitivity && analogRead(T3)>sensitivity)
    {
      i++;//loop break condition
    }
  }
}
