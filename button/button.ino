int led=13; 
int button=2; 
int Cst;
int Pst=HIGH; 
int count;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT); 
pinMode(button,INPUT); 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Cst=digitalRead(button);
if(Cst != Pst){
  Cst=digitalRead(button);  
  delay(50);
  if(Cst==LOW){
    digitalWrite(led,HIGH); 
    delay(1000);
    digitalWrite(led,LOW); 
    count++; 
    Serial.println(count);
    }  
    
  }
 Pst=Cst;  
 //digitalWrite(led,LOW);
}
