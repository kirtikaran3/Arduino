int button=2; 
int count=0;

int pst=LOW;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(button,INPUT);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

  int cst = digitalRead(button); 

if(pst!=cst){
   
  if(cst==LOW){
    count++;
    } 
}
  Serial.print("Count value :      "); 
  Serial.println(count);
pst=cst;
}
