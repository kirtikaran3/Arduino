#include<WiFi.h> 
const char* ssid = "D-1901"; 
const char* password = "@$machine30#*"; 
 void setup() {
  // put your setup code here, to run once:

Serial.begin(115200); 
delay(10); 

WiFi.begin(ssid,password); 

Serial.println(); 
Serial.println();  
Serial.print("Connecting to :"); 
Serial.println(ssid); 
WiFi.begin(ssid,password); 

while(WiFi.status()!=WL_CONNECTED){
  delay(500); 
  Serial.print(".");
  } 
  Serial.println(""); 
  Serial.println("WiFi Connected");
}


void loop() {
  // put your main code here, to run repeatedly:
Serial.print("You are connected to : ");
Serial.println(ssid); 
delay(1000);
}
